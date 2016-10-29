#include "SpiderBot.h"
/*
*   Move to a set position with no rate or acceleration consideration. 
*   Most useful for holding a set position or fast movements.
*/
int16_t moveToPos(jointData_t* joint)
{
  float dt = 0.005; // PID update time in seconds
  float error = joint->target_pos - joint->current_pos;
  float prop = joint->p_pos * error;
  joint->integral += joint->i_pos * (error*DT);
  float deriv = joint->d_pos * (error*DT_INV);

  float integral_pos = joint->integral_pos;

  int16_t response = (int)(prop + joint->integral_pos - deriv);

  if(integral_pos > 125)
  {
    integral_pos = 125;
  }
  else if(integral_pos < -125)
  {
    integral_pos = -125;
  }
  
  if(response > 250)
  {
    response = 250;
  }
  else if(response < -250)
  {
    response = -250;
  }
  return response;
}

/*
*   Move to a position with velocity and acceleration considerations. Uses
*   jointData_t object's current set rate and acceleration profile selection.
*/
int16_t moveToPosWithAccl(jointData_t* joint)
{
  // Position variables
  float currrent_pos = joint->current_pos;
  float target_pos = joint->target_pos;
  // Velocity variables
  float current_vel = joint->current_vel;
  float target_vel = joint->target_vel;
  // PID variables
  float dt = 0.005; // PID update time in seconds
  float error;
  float prop;
  float deriv;
  int16_t response;
  if(atPosition(current_pos,target_pos))
  {
    response = moveToPos(joint);
  }
  else
  {
    float error = do this maths;
    float prop = joint->p_vel * error;
    joint->integral_vel += joint->i_vel * (error*DT);
    float deriv = joint->d_pos * (error*DT_INV);

    response = (int)(prop + joint->integral_vel - deriv);

    if(joint->integral_vel > 125)
    {
      joint->integral_vel = 125;
    }
    else if(joint->integral_vel < -125)
    {
      joint-> integral_vel = -125;
    }
    
    if(response > 250)
    {
      response = 250;
    }
    else if(response < -250)
    {
      response = -250;
    } 
  }

  return response;
}

/* 
*  Move at a set rate (positive or negative) and diregaurd position except for 
*  known mechanical limits.
*/
int16_t moveAtRate(jointData_t* joint)
{

}

/*
*  Check if the joint is at a given position to within the defined margin of
*  error.
*/
uint8_t atPosition(float current_pos, float target_pos)
{
  float dif = current_pos - target_pos;
  if(dif < 0)
  {
    dif = dif*-1;
  }
  if(dif < POSITION_DEADZONE)
  {
    return 1;
  }
  return 0;
}
