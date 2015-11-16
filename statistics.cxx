#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;



double random(double* pointer, const int N);							//put random variables in to a given array
double statistic(double* point, const int N, double& mean, double& var);		//calulate the expectation value and Variance of a given array 



int main(){
   srand(time(NULL));						//create new seed for rand()
   const int N = 100;						//lenght of vector p, contains random var between 0 and 1
   double p[N];
   double mean, var;

   random(p,N);

   statistic(p,N,mean,var);
   
   cout << "Mean = " << mean << endl;
   cout << "Variance = " << var << endl;
   

   return 0;
}





/*
 * 
 * 
 * Definition of functions
 * 
 * 
 * 
 */



double random(double* pointer, const int N){
  for(int i=0; i<N;i++){
    pointer[i]=rand() % 10 + 0;					//generate a random number between 0 and 1
    pointer[i]=pointer[i]/10;					// 
  }
  return 0;
}


double statistic(double* point, const int N, double& mean, double& var){
  double sum=0;
  for(int i=0; i<N;i++)						//calculate mean value
  {
    sum += point[i];						//sum of all x_i
  }
  mean = sum/N;							// sum(x_i)/N 
  
  
  sum=0;							//calculate variance value, set sum again to 0 or else sum contains sumation of the mean-forloop
  for(int j=0;j<N;j++)
  {
    sum += pow((point[j]-mean),2);				//sum((x_i - mean)^2)
  }
  var=sum/N;							//sum(...)/N
  return 0;							//due to references the solution of the calculations are saved at mean and var. The return of the function don't have to be changed.
}