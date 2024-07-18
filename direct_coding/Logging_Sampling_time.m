%% Load data 
data=load('wrong_timestamps_demostration_data.mat')

%% Checking timestamps of control input

% Remove the first 20 samples

timestamps = data.timestamps;

n=1;


for i=2:size(timestamps);
    if timestamps(i)-timestamps(i-1) > 0.00401
        expired(n) = i;
        n=n+1;
        fprintf("The difference between %d-th timestamp and the %d-th timestamp is greater than Ts: difference is %f\n",i+1,i,timestamps(i)-timestamps(i-1))
    end
end