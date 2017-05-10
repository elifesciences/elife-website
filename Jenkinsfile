elifePipeline {
    stage 'Checkout'
    checkout scm
    def commit = elifeGitRevision()

    // Project tests are run on Travis CI at the moment

    stage 'End2end tests'
    elifeSpectrum(
        deploy: [
            stackname: 'elife-website--end2end',
            revision: commit,
            folder: '/srv/website'
        ]
    )

    stage 'Approval'
    elifeGitMoveToBranch commit, 'approved'
}
// just some testing
