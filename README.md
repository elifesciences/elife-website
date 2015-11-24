
# Notes for branch `feature/introduce-galen-tests`

## Manual Galen setup on Mac host

### Install dependencies
1. If you've not already got Homebrew installed, follow the instructions at [http://brew.sh/](http://brew.sh/)

1. `brew update`

1. `brew install galen` will install the current version of Galen and make it available at `galen`. If you already installed Galen via another route, brew may warn of overriding paths. Use the command brew suggests to make the breq-installed version of Galen available with the `galen` command.

1. `brew install phantomjs` will install that headless browser.

1. Ensure Selenium is installed. Get it from [http://www.seleniumhq.org/](http://www.seleniumhq.org/) 

### Run tests

1. Once everything is installed, you should be able to run the tests by:
 
 ```./run-galen-tests.sh```
 
1. Write more tests! Add tests to `tests/galen/test/`, and add specs to `tests/galen/tests/spec/[grouping]/` 

