elifePipeline {
    stage 'Checkout'
    checkout scm
    def commit = elifeGitRevision()

    // Project tests are run on Travis CI at the moment

    stage 'End2end tests'
    elifeEnd2EndTest {
        builderDeployRevision 'elife-website--end2end', commit
    }

    stage 'Approval'
    elifeGitMoveToBranch commit, 'approved'
}
