% Define the simulation time
t = linspace(0, 10, 1000);

s = tf('s');
G = 7.2343 / (1 + (s* 0.065));

% Input vector
input = [100, 20, 30, 40, 50, 60, 70, 80, 90, 100, 50, 100, 70, 20, 50, 100, 10, 5, 15, 50, 100];
input = (input *12) /100
% Vettore degli output calcolati come medie
output = [82.15, 15.725, 24.275, 32.875, 41.425, 50, 57.875, 66.45, 75, 83.55, 42.125, 84.275, 59.3, 15.725, 42.15, 85, 7.125, 2.15, 12.15, 42.15, 85];

%input= [100, 100]
%output=[82.15, 83.55]

p=polyfit(input,output,1)
new_gain = p(1);
fprintf('The gain of the model is: %.2f for a unit of control input\n', new_gain);

output_pred = polyval(p, input);

plot(input, output, 'o'); % Original data
hold on;
plot(input, output_pred, '-'); % Estimated mode
hold off;
xlabel('Control Input (%)');
ylabel('Output Speed (RPM)');
legend('Measured data', 'Approximated Model');
title('Motor model approximation');

% Define the new transfer function with the new gain
G_new = (new_gain ) / (1 + (s* 0.065));

%Step responses
[y_orig, t_orig] = step(G, t);
[y_new, t_new] = step(G_new,t);


% Step responses comparison
figure;
plot(t, y_orig, 'b', 'LineWidth', 1);
hold on;
plot(t, y_new, 'r', 'LineWidth', 1);
hold off;
xlabel('Time (s)');
ylabel('Response');
legend('Original', 'New gain');
title('Step responses comparison');
grid on;


