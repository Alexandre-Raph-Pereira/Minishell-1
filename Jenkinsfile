pipeline {
  agent any
  stages {
    stage('Built') {
      steps {
        git(branch: 'pipeline', url: '7b2551ddc05aa4c696a449f86d95502368bdc15b')
        sh 'make'
      }
    }
    stage('Test') {
      steps {
        sh 'make tests_run'
        archiveArtifacts '*.gcno'
      }
    }
    stage('Deploy') {
      steps {
        echo 'it\'s finish'
      }
    }
  }
}