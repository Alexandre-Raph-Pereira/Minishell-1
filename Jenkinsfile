pipeline {
  agent any
  stages {
    stage('Built') {
      steps {
        sh 'git checkout test'
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