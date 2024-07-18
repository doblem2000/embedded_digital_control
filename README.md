# Embedded Digital Controllers Project Work

## Authors
- Michele Marsico
- Adamo Zito

## Project Directory Structure

### direct_coding Folder:
- `position_control_direct_coding`: C project using STM IDE for position control.
- `torque_control_direct_coding`: C project using STM IDE for torque control.
- `logging.m`: MATLAB script for reading the results of direct coding and generating plots.
- `Logging_Sampling_time.m`: MATLAB script for verifying that control inputs are sent with the correct timestamps.
- `read_position_control.mat`: Recorded file for direct coding of position control.
- `read_torque_control.mat`: Recorded file for direct coding of torque control.
- `wrong_timestamps_demonstration_data`: Recorded timestamps to demonstrate serial port saturation below a certain sampling time.

### position_control Folder:
- `position_control_cyclic_motor_sm.slx`: Simulink file for position control on the real motor with cyclic error behavior.
- `position_control_motor_sm.slx`: Simulink file for position control on the real motor.
- `position_control_motor_wu_bt_sm.slx`: Simulink file for comparing cases with and without windup, and with and without bumpless transfer on the real motor.
- `position_control_simulation.slx`: Simulink file for position control in simulation.
- `position_control.mlx`: MATLAB Live Editor document for position control.

### position_model Folder:
- `AreasMethod.m`: MATLAB function for computing T and tau using the areas approach.
- `FOPDT_Model.mlx`: Live script for obtaining the transfer function from the motor step response.
- `better_gain.m`: MATLAB script for improving the transfer function gain.
- `matlab_speed_measures.mat`: Recorded step response of the real motor used by the areas approach.
- `open_loop.slx`: Open-loop Simulink model of the real motor.

### Utility Folders:
- `quadratureEncoder_module`: Utility folder for interfacing with the real motor.
- `readFromCOM`: Utility folder for reading data from the serial port.
they need to be included in the Matlab path

### SIL_PIL Folder:
- `position_control_PIL.slx`: Simulink model for Processor-in-the-Loop (PIL) execution of position control.
- `position_control_SIL.slx`: Simulink model for Software-in-the-Loop (SIL) execution of position control.
- `position_Control_z.slx`: Simulated Simulink model for SIL and PIL execution of position control.
- `torque_control_PIL.slx`: Simulink model for Processor-in-the-Loop (PIL) execution of torque control.
- `torque_control_SIL.slx`: Simulink model for Software-in-the-Loop (SIL) execution of torque control.
- `torque_Control_z.slx`: Simulated Simulink model for SIL and PIL execution of torque control.
- `SIL_PIL_control.mlx`: Live script for executing SIL and PIL for both position and torque control.

### torque_control Folder:
- `torque_control_motor_sm.slx`: Simulink model for torque control on the real motor.
- `torque_control_simulation_sm.slx`: Simulink model for torque control in simulation.
- `Torque.mlx`: Live script for designing and implementing torque control.

### torque_model Folder:
- `motor_parameters.m`: MATLAB script with motor parameters and the current process transfer function.


This project involves the development and implementation of embedded digital controllers for position and torque control of a DC motor. Various models and control strategies are explored using MATLAB, Simulink, and STM IDE for both simulation and real-time applications.
```

