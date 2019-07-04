pipeline {
  agent any
  stages {
    stage('Built') {
      steps {
        sh 'git pull'
        sh 'git checkout test'
        sh 'git log'
        sh 'cat tests/unit_tests.c '
        sh 'make'
      }
    }
    stage('Test') {
      steps {
        sh 'make tests_run'
      }
    }
    stage('Deploy') {
      steps {
        echo 'it\'s finish'
      }
    }
  }
}