pipeline {
  agent any
  stages {
    stage('Built') {
      steps {
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