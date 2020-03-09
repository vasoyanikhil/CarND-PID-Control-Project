#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp=Kp_;
  Ki=Ki_;
  Kd=Kd_;
  
  //error variable initalize with zero
  p_error=0;
  i_error=0;
  d_error=0;
  
  int_cte=0;
  diff_cte=0;
  prev_cte=0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  //calculate potential error 
  p_error= Kp * cte;
  
  //sum of all cte error
  int_cte +=cte;
  
  //calculate i error
  i_error= Ki * int_cte;
  
  //difference of the current cte value and previous cte value.
  diff_cte=cte-prev_cte;
  prev_cte=cte;
  
  //calculate d error
  d_error= Kd * diff_cte;

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
   double steer;
   //total error
   steer= -p_error - i_error - d_error;
  return steer;  // TODO: Add your total error calc here!
}