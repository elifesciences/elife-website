/**
 * ALMViz
 * See https://github.com/jalperin/almviz for more details
 * Distributed under the GNU GPL v2. For full terms see the file docs/COPYING.
 *
 * @brief Article level metrics visualization controller.
 */
function AlmViz(options) {

  // allow jQuery object to be passed in
  // in case a different version of jQuery is needed from the one globally defined
  var $ = options.jQuery || jQuery;

  // Init data
  var categories_ = options.categories;
  var data = options.almStatsJson;
  var additionalStats = options.additionalStatsJson;

  // Init basic options
  var baseUrl_ = options.baseUrl;
  var hasIcon = options.hasIcon;
  var minItems_ = options.minItemsToShowGraph;
  var showTitle = options.showTitle;
  var showSources = options.showSources;
  var showSourceLinks = options.showSourceLinks;
  var chartheight = options.chartHeight;
  var chartwidth = options.chartWidth;
  var dailyNDays = options.dailyNDays;

  var gapWidth = 2;
  var formatNumber_ = d3.format(",d");
  var vizDiv;

  var loadData_,
    addCategory_,
    getCategoryRow_,
    addSource_,
    getDate_,
    getDateFormat_,
    getData_,
    getTimeInterval_,
    getViz_,
    makeGraph_,
    makeSourceCountTitle_;

  // Oldest date represented on the graph.
  var pubDate,
  // Publication date of article.
    pubDateStore,
    hasSVG_,
  // to track if any metrics have been found
    metricsFound_;

  /**
   * Initialize the visualization.
   * NB: needs to be accessible from the outside for initialization
   */
  this.initViz = function () {
    vizDiv.select(".loading").remove();

    if (showTitle) {
      vizDiv.append("a")
        .attr('href', 'http://dx.doi.org/' + data[0].doi)
        .attr("class", "title")
        .text(data[0].title);
    }

    // loop through categories
    categories_.forEach(function (category) {
      addCategory_(vizDiv, category, data);
    });

    if (!metricsFound_) {
      vizDiv.append("p")
        .attr("class", "muted")
        .text("No metrics found.");
    }
  };

  /**
   * The basic general set up of the graph itself
   *
   * @param {JQueryElement} chartDiv The div where the chart should go
   * @param {Object} source The data source, containing summary and detailed
   * data, possibly at several levels of detail.
   * @param {Array} category The category for 86 chart
   * @return {Object}
   */
  getViz_ = function (chartDiv, source, category) {
    var viz = {};

    // size parameters
    viz.margin = {top: 5, right: 5, bottom: 30, left: 40};
    viz.width = chartwidth - viz.margin.left - viz.margin.right;
    viz.height = chartheight - viz.margin.top - viz.margin.bottom;

    // div where everything goes
    viz.chartDiv = chartDiv;

    // source data and which category
    viz.category = category;
    viz.source = source;

    // just for record keeping
    viz.name = source.name + '-' + category.name;

    viz.x = d3.time.scale();
    viz.x.range([0, viz.width]);

    viz.y = d3.scale.linear();
    viz.y.range([viz.height, 0]);

    viz.z = d3.scale.ordinal();
    viz.z.range(['main', 'alt']);

    // The chart SVG element.
    viz.svg = viz.chartDiv.append("svg")
      .attr("width", viz.width + viz.margin.left + viz.margin.right)
      .attr("height", viz.height + viz.margin.top + viz.margin.bottom)
      // create a transformed group for the data area
      .append("g")
      .attr("transform", "translate(" + (viz.margin.left) + "," + (viz.margin.top) + ")");

    // draw the bars g first so it ends up underneath the axes
    viz.bars = viz.svg.append("g");

    // and the shadow bars on top for the tooltips
    viz.barsForTooltips = viz.svg.append("g");

    // now the x and y axis bars.
    viz.svg.append("g")
      .attr("class", "x axis")
      .attr("transform", "translate(0," + (viz.height) + ")");

    // now the x and y axis bars.
    viz.svg.append("g")
      .attr("class", "y axis");

    return viz;
  };

  /**
   * Build each article level statistics category.
   *
   * @param {Object} canvas d3 element
   * @param {Array} category Information about the category.
   * @param {Object} data Statistics.
   */
  addCategory_ = function (canvas, category, data) {
    var $categoryRow = false;

    // Loop through sources to add statistics data to the category.
    data[0]["sources"].forEach(function (source) {
      var total = source.metrics[category.name];
      if (total > 0) {
        // Only add the category row the first time
        if (!$categoryRow) {
          $categoryRow = getCategoryRow_(canvas, category);
        }

        // Flag that there is at least one metric
        metricsFound_ = true;
        addSource_(source, total, category, $categoryRow);
      }
    });
  };

  /**
   * Get category row d3 HTML element. It will automatically
   * add the element to the passed canvas.
   *
   * @param {Object} canvas d3 element
   * @param {Array} category Information about the category.
   * @return {Object} jQuery object representing the new chart container
   */
  getCategoryRow_ = function (canvas, category) {
    var categoryRow,
      categoryTitle,
      tooltip;

    // Build category html objects.
    categoryRow = canvas.append("div")
      .attr("class", "alm-category-row")
      .attr("style", "width: 100%; overflow: hidden;")
      .attr("id", "category-" + category.name);

    categoryTitle = categoryRow.append("h2")
      .attr("class", "alm-category-row-heading")
      .attr("id", "month-" + category.name)
      .text(category.display_name);

    tooltip = categoryTitle.append("div")
      .attr("class", "alm-category-row-info").append("span")
      .attr("class", "ui-icon ui-icon-info");

    $(tooltip).tooltip({title: category.tooltip_text, container: 'body'});

    return categoryRow;
  };

  /**
   * Add the graph to the element.
   *
   * @param {Object} source The data source, containing summary and detailed
   *          data, possibly at several levels of detail.
   * @param {Array} category Information about the category.
   * @param {Object} $row jQuery element which contains the graph.
   */
  makeGraph_ = function (source, category, $row) {
    var level;
    var levelData;
    // check what levels we can show
    var showDaily = false,
      showMonthly = false,
      showYearly = false,
      yearTotal,
      monthTotal,
      dayTotal,
      numYears,
      numMonths,
      numDays;

    // Verify the sources that can be provided have data available and
    // check that data against the conditions set up in the configuration;
    // sources with insufficient data at a particular granularity are not
    // displayed.

    if (source.by_year) {
      levelData = getData_('year', source);
      yearTotal = levelData.reduce(function (i, d) {
        return i + d[category.name];
      }, 0);
      numYears = d3.time.year.utc.range(pubDate, new Date()).length;

      if (yearTotal >= minItems_.minEventsForYearly &&
          numYears >= minItems_.minYearsForYearly) {
        showYearly = true;
        level = 'year';
      }
    }

    if (source.by_month) {
      levelData = getData_('month', source);
      monthTotal = levelData.reduce(function (i, d) {
        return i + d[category.name];
      }, 0);
      numMonths = d3.time.month.utc.range(pubDateStore, new Date()).length;

      if (monthTotal >= minItems_.minEventsForMonthly &&
          numMonths >= minItems_.minMonthsForMonthly) {
        showMonthly = true;
        level = 'month';
      }
    }

    if (source.by_day) {
      levelData = getData_('day', source);
      dayTotal = levelData.reduce(function (i, d) {
        return i + d[category.name];
      }, 0);
      numDays = d3.time.day.utc.range(pubDate, new Date()).length;

      if (dayTotal >= minItems_.minEventsForDaily && numDays >= minItems_.minDaysForDaily) {
        showDaily = true;
        level = 'day';
      }
    }

    // The level and levelData should be set to the finest level of
    // granularity that we can show. This is done by, for each finer level,
    // cheching to see if it can be displayed and if so setting 'level' to
    // that level.

    // check there is data
    if (showDaily || showMonthly || showYearly) {
      var $chartDiv,
        viz,
        updateControls_;

      // Swap around the classes on controls to indicate activity
      updateControls_ = function (control) {
        control.siblings('.alm-control').removeClass('active');
        control.addClass('active');
      };

      $chartDiv = $row.append("div")
        .attr("class", "alm-chart-area");

      viz = getViz_($chartDiv, source, category);
      loadData_(viz, level);

      var $levelControlsDiv = $chartDiv.append("div")
        .attr("style", "width: " + (viz.margin.left + viz.width) + "px;")
        .append("div")
        .attr("style", "float:right;");

      // only show the control if there are at least 2 options
      if (showDaily && (showMonthly || showYearly)) {
        $levelControlsDiv.append("a")
          .attr("href", "javascript:void(0)")
          .classed("alm-control", true)
          .classed("disabled", !showDaily)
          .classed("active", (level == 'day'))
          .text("daily (last " + (dailyNDays + 1).toString() + ")")
          .on("click", function () {
            if (showDaily && !$(this).hasClass('active')) {
              loadData_(viz, 'day');
              updateControls_($(this));
            }
          }
        );
        $levelControlsDiv.append("text")
          .text(" | ");
      }

      if (showMonthly && (showDaily || showYearly)) {
        $levelControlsDiv.append("a")
          .attr("href", "javascript:void(0)")
          .classed("alm-control", true)
          .classed("disabled", !showMonthly)
          .classed("active", (level == 'month'))
          .text("monthly")
          .on("click", function () {
            if (showMonthly && !$(this).hasClass('active')) {
              loadData_(viz, 'month');
              updateControls_($(this));
            }
          }
        );

        if (showYearly) {
          $levelControlsDiv.append("text")
            .text(" | ");
        }
      }

      if (showYearly && (showMonthly || showDaily)) {
        $levelControlsDiv.append("a")
          .attr("href", "javascript:void(0)")
          .classed("alm-control", true)
          .classed("disabled", !showYearly)
          .classed("active", (level == 'year'))
          .text("yearly")
          .on("click", function () {
            if (showYearly && !$(this).hasClass('active')) {
              loadData_(viz, 'year');
              updateControls_($(this));
            }
          }
        );
      }

      // add a clearer and styles to ensure graphs on their own line
      $row.insert("div", ":first-child")
        .attr('style', 'clear:both');
      $row.attr('style', "width: 100%");
    }
  };

  /**
   * Add the source title & count label block. This block can contain
   * the total article count, and the name of the data source. The name
   * can also be linked to another page that 'elaborates' the data source
   * in some way.
   *
   * @param {Object} source The data source, containing summary and detailed
   *          data, possibly at several levels of detail.
   * @param {int} sourceTotalValue Total of number of events for this graph,
   *          eg total page views.
   * @param {Array} category Information about the category.
   * @param {Object} $row jQuery element which contains the graph.
   */
  makeSourceCountTitle_ = function (source, sourceTotalValue, category, $row) {
    var $countLabel, $count;

    $countLabel = $row.append("div")
      .attr("class", "alm-count-label");

    if (hasIcon.indexOf(source.name) >= 0) {
      $countLabel.append("img")
        .attr("src", baseUrl_ + '/assets/' + source.name + '.png')
        .attr("alt", 'a description of the source')
        .attr("class", "label-img");
    }

    if (source.events_url) {
      // if there is an events_url, we can link to it from the count
      $count = $countLabel.append("a")
        .attr("href", function () {
          return source.events_url;
        });
    }
    else {
      // if no events_url, we just put in the count
      $count = $countLabel.append("span");
    }

    $count
      .attr("class", "alm-count")
      .attr("id", "alm-count-" + source.name + "-" + category.name)
      .text(formatNumber_(sourceTotalValue));

    $countLabel.append("br");

    if (source.name == 'pkpTimedViews') {
      $countLabel.append("span")
        .text(source.display_name);
    }
    else if (showSources) {
      // link the source name
      if (showSourceLinks) {
        $countLabel.append("a")
          .text(source.display_name);
        $countLabel.attr("href", baseUrl_ + "/sources/" + source.name);
      }
      else {
        // show the source name
        $countLabel.append("p")
          .text(source.display_name);
      }
    }
  };

  /**
   * Add source information to the passed category row element.
   *
   * @param {Object} source The data source, containing summary and detailed
   *          data, possibly at several levels of detail.
   * @param {int} sourceTotalValue Total of number of events for this graph,
   *          eg total page views.
   * @param {Array} category Information about the category.
   * @param {Object} $categoryRow jQuery element to which the new graph will
   *         be added.
   * @return {Object}
   */
  addSource_ = function (source, sourceTotalValue, category, $categoryRow) {
    var $row;

    $row = $categoryRow
      .append("div")
      .attr("class", "alm-row")
      .attr("style", "float: left")
      .attr("id", "alm-row-" + source.name + "-" + category.name);

    makeSourceCountTitle_(source, sourceTotalValue, category, $row);

    // Only add a chart if the browser supports SVG
    if (hasSVG_) {
      makeGraph_(source, category, $row);
    }

    return $row;
  };

  /**
   * Read the date for a given datum from the source. The value of
   * level changes the granularity of the returned date object.
   *
   * @param {string} level (day|month|year)
   * @param {Object} d the datum
   * @return {Date} A php Date object.
   */
  getDate_ = function (level, d) {
    switch (level) {
      case 'year':
        return new Date(d.year, 0, 1, 1, 0);
      case 'month':
        // js Date indexes months at 0
        return new Date(d.year, d.month - 1, 1, 1, 0);
      case 'day':
        // js Date indexes months at 0
        return new Date(d.year, d.month - 1, d.day, 1, 0);
      default:
        return new Date(d.year, d.month - 1, d.day, 1, 0);
    }
  };

  /**
   * Returns a d3 date format for date operations. The level parameter
   * affects the granularity of the returned format.
   *
   * @param {string} level (day|month|year)
   * @param {Object} d the datum
   * @return {String}
   */
  getDateFormat_ = function (level) {
    switch (level) {
      case 'year':
        return d3.time.format("%Y");
      case 'month':
        return d3.time.format("%b %y");
      case 'day':
        return d3.time.format("%d %b %y");
      default:
        return d3.time.format("%d %b %y");
    }
  };


  /**
   * Extract the data from the source.
   *
   * @param {string} level (day|month|year)
   * @param {Object} source The data source, containing summary and detailed
   *          data, possibly at several levels of detail.
   * @return {Array} Metrics
   */
  getData_ = function (level, source) {
    switch (level) {
      case 'year':
        return source.by_year;
      case 'month':
        return source.by_month;
      case 'day':
        return source.by_day;
      default:
        return [];
    }
  };

  /**
   * Returns a d3 date object for date operations.
   *
   * @param {string} level (day|month|year
   * @return {Object} d3 time Interval
   */
  getTimeInterval_ = function (level) {
    switch (level) {
      case 'year':
        return d3.time.year.utc;
      case 'month':
        return d3.time.month.utc;
      case 'day':
        return d3.time.day.utc;
      default:
        return d3.time.day.utc;
    }
  };

  /**
   * Takes in the basic set up of a graph and loads the data itself.
   *
   * @param {Object} viz AlmViz object
   * @param {string} level (day|month|year)
   */
  loadData_ = function (viz, level) {
    var category,
      timeInterval;
    var levelData,
      filteredLevelData;
    var startDate,
      endDate;
    var barWidthInTime,
      barWidth;
    var bars,
      barsForTooltips;

    // functions
    var barClasses,
      barToolClasses,
      barHeight,
      barXPos,
      barYPos,
      barData,
      filterData,
      dataKeyFunc;

    //         === Local Functions ===

    /**
     * Account for the 30-day view: produce a version of the level data which
     * has only the data we intend to use for this graph.
     */
    filterData = function (d) {
      var dt;
      dt = getDate_(level, d);
      return (dt >= startDate) && (dt < endDate);
    };

    /**
     * Return a data key value which also specifies the x-value of the bar
     * on the graph.
     */
    dataKeyFunc = function (d) {
      return getDate_(level, d);
    };

    /**
     * Return the css classes that will be applied to the visible bars. All
     * bars have class 'bar' which is used to 'address' them using selectAll(),
     * and another class is applied to be able to highlight different weeks or
     * months, using the z-axis (see z-range definition).
     */
    barClasses = function (d) {
      var tmClass;
      tmClass = (level == 'day') ?
        d3.time.weekOfYear(getDate_(level, d)) :
        d.year;
      // z(tmClass) is 'main' or 'alt'
      return "bar " + viz.z(tmClass);
    };

    /**
     * As for barClasses, but these are applied to the tooltip bars (which are
     * invisible). A class is applied to be able to highlight different weeks or
     * months, using the z-axis.
     */
    barToolClasses = function (d) {
      var tmClass;
      tmClass = (level == 'day') ?
        d3.time.weekOfYear(getDate_(level, d)) :
        d.year;
      return "barsForTooltip " + viz.z(tmClass);
    };

    /**
     * Return the position on the X axis for the bar. This is the left-hand edge
     * of the bar, corresponding to the earliest date.
     */
    barXPos = function (d) {
      var dt = getDate_(level, d);
      return viz.x(dt);
    };

    /**
     * Return the Y position of the bar.
     */
    barYPos = function (d) {
      return viz.y(d[category.name]);
    };

    /**
     * Return the bar height. The height transform is needed because of the
     * inversion of the Y axis c.f. SVG coordinates.
     */
    barHeight = function (d) {
      return viz.height - viz.y(d[category.name]);
    };

    /**
     * Return the unscaled bar data for the bar.
     */
    barData = function (d) {
      return d[category.name];
    };


    category = viz.category;
    timeInterval = getTimeInterval_(level);

    startDate = timeInterval.floor(pubDate);
    endDate = new Date();
    // use only last N days if using day view
    if (level == 'day') {
      pubDate = timeInterval.offset(endDate, -dailyNDays);
      startDate = timeInterval.floor(pubDate);
    } else {
      pubDate = pubDateStore;
      startDate = timeInterval.floor(pubDate);
    }

    levelData = getData_(level, viz.source);

    // filterData uses startDate & endDate
    filteredLevelData = levelData.filter(filterData);

    // a time x axis, between startDate and endDate
    viz.x.domain([startDate, endDate]);

    // a linear axis from 0 to max value found
    viz.y.domain([0, d3.max(filteredLevelData, barData)]);

    // ask the scale component how wide a bar is by asking
    // for x at dates that are a day|month|year apart.
    barWidthInTime = timeInterval.offset(startDate, 1);
    barWidth = viz.x(barWidthInTime) - viz.x(startDate);
    barWidth = Math.max(barWidth - gapWidth, 1);

    // a linear axis between publication date and current date
    viz.xAxis = d3.svg.axis()
      .scale(viz.x)
      .tickSize(4)
      .ticks(5)
      .tickFormat(getDateFormat_(level));

    // a linear y axis between 0 and max value found in data
    viz.yAxis = d3.svg.axis()
      .scale(viz.y)
      .orient("left")
      .tickSize(4)
      .ticks(4)
      .tickFormat(d3.format(",d"));


    // The bars to which tooltips are attached are separate from the visible ones.
    barsForTooltips = viz.barsForTooltips.selectAll(".barsForTooltip")
      .data(filteredLevelData, dataKeyFunc);

    // delete tooltip bars from the DOM
    barsForTooltips
      .exit()
      .remove();

    // Clear out any prior registration of the dataset with D3 layer, as when we
    // go from daily to monthly there can be up to 2 data points which have the
    // same date, and thus are not cleared out in the normal way. For reasons
    // I don't understand, the D3 layer code modifies those two elements to some
    // extent (colour, height) but does not change the x axis position properly.
    // The code here addresses this problem by unsetting the data array, then
    // deleting the unassociated elements (which is therefore all of them), so
    // forcing D3 to regenerate the complete element set each time.
    viz.bars.selectAll(".bar")
      .data([])
      .exit()
      .remove();

    // Make a selection of the bars and associated the filtered data set with
    // them.
    bars = viz.bars.selectAll(".bar")
      .data(filteredLevelData, dataKeyFunc);

    // delete any unassociated bars (NB with the delete code above, this should
    // have nothing to do, but left like this for the moment.)
    bars
      .exit()
      .remove();

    // For each bar, append a rect element and set class, height, width, x and y
    // The height is initially 0 because we transition it to its proper value.
    bars
      .enter()
      .append("rect")
      .attr("width", barWidth)
      .attr("height", 0)
      .attr("x", barXPos)
      .attr("y", viz.height)
      .attr("class", barClasses);

    // A transition which changes the height and Ypos of the bar so it appears
    // to grow from the bottom upwards.
    bars.transition()
      .duration(1000)
      .attr("width", barWidth)
      .attr("y", barYPos)
      .attr("height", barHeight);

    // A transition which - very quickly - makes the bars shrink to 0-height
    // when the dataset is changed - ie when a new dataset is loaded.
    bars
      .exit().transition()
      .attr("y", viz.height)
      .attr("height", 0);

    viz.svg
      .select(".x.axis")
      .call(viz.xAxis);

    // A transition matching that for the bars themselves so that the Y axis stays
    // in sync with the bar height..
    viz.svg
      .transition().duration(1000)
      .select(".y.axis")
      .call(viz.yAxis);

    barsForTooltips
      .enter().append("rect")
      .attr("class", barToolClasses);

    barsForTooltips
      .attr("width", barWidth)
      .attr("x", barXPos)
      .attr("y", barYPos)
      .attr("height", barHeight);

    // add in some tool tips on data values.
    viz.barsForTooltips.selectAll("rect").each(
      function (d) {
        $(this).tooltip('destroy'); // need to destroy so all bars get updated
        $(this).tooltip({title: formatNumber_(d[category.name]), container: "body"});
      }
    );
  };

  // ------------------------- ====================== -------------------------

  if (additionalStats) {
    data[0].sources.push(additionalStats);
  }

  // Get the Div where the viz should go (default to one with ID "alm')
  if (options.vizDiv) {
    vizDiv = d3.select(options.vizDiv);
  }
  else {
    vizDiv = d3.select("#alm");
  }

  // extract publication date
  if (!(data && data[0])) {
    vizDiv.append("p")
      .attr("class", "muted")
      .text("Page view data not available : the server could not be contacted.")
    return this;
  }
  pubDateStore = pubDate = d3.time.format.iso.parse(data[0]["publication_date"]);

  // look to make sure browser support SVG
  hasSVG_ = document.implementation.hasFeature("http://www.w3.org/TR/SVG11/feature#BasicStructure", "1.1");
}
