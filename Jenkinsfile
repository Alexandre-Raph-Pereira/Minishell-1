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
        archiveArtifacts '*.gcno *.gcda'
      }
    }
    stage('Deploy') {
      steps {
        echo 'it\'s finish'
      }
    }
  }
}