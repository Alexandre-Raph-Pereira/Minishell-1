pipeline {
  agent any
  stages {
    stage('Built') {
      steps {
        sh '''
make re'''
      }
    }
    stage('Test') {
      steps {
        sh 'make tests_run'
        sh 'gcovr'
      }
    }
    stage('Deploy') {
      steps {
        echo 'it\'s finish'
      }
    }
  }
}