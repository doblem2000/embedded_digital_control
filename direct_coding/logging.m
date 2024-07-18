%% Data logging
clear; close all; clc

data=readFromCOM('COM3',true);

% Record position control
% 1)Timestamp,
% 2)Position,
% 3)Control input
% 4)Speed
% 5)Error
% 6)Reference
% 7)Cycle Begin Delay
% 8)Cycle Core Duration

% Record torque control
% 1)Timestamp,
% 2)Position,
% 3)Control input
% 4)Speed
% 5)Error
% 6)Reference
% 7)Current
% 8)Cycle Begin Delay
% 9)Cycle Core Duration


%% Data plotting position
% Combined plot: Tempo vs Speed in RPM and Posizione in radianti al secondo

% Remove the first 20 samples
data_reduce = data(21:end, :);

figure();
hold on

% Plot Speed
yyaxis left
plot(data_reduce(:,1) * 0.001, data_reduce(:,4), '-r', 'DisplayName', 'Speed (RPM)'); % velocità
ylabel('Speed (RPM)'); % Etichetta dell'asse y (left)
ax = gca; % Get current axes
ax.YColor = 'r'; % Set y-axis color to red

% Plot Posizione, Errore, and Riferimento
yyaxis right
plot(data_reduce(:,1) * 0.001, data_reduce(:,2), '-b', 'DisplayName', 'Posizione (rad)'); % posizione
plot(data_reduce(:,1) * 0.001, data_reduce(:,5), '-g', 'DisplayName', 'Errore'); % errore
plot(data_reduce(:,1) * 0.001, data_reduce(:,6), '-m', 'DisplayName', 'Riferimento'); % riferimento
ylabel('Posizione (rad/s)'); % Etichetta dell'asse y (right)
ax.YColor = 'b'; % Set y-axis color to blue

xlabel('Time (s)'); % Etichetta dell'asse x
title('Motor Speed and Position'); % Titolo del grafico
grid on; % Mostra la griglia

% Add legend
legend('show');

hold off


% Plot Posizione, Errore, and Riferimento
figure();
hold on

plot(data_reduce(:,1) * 0.001, data_reduce(:,2), '-b', 'DisplayName', 'Posizione (rad)'); % posizione
plot(data_reduce(:,1) * 0.001, data_reduce(:,5), '-g', 'DisplayName', 'Errore'); % errore
plot(data_reduce(:,1) * 0.001, data_reduce(:,6), '-m', 'DisplayName', 'Riferimento'); % riferimento
ylabel('Posizione (rad/s)'); % Etichetta dell'asse y
xlabel('Time (s)'); % Etichetta dell'asse x
title('Position, Error, and Reference'); % Titolo del grafico
grid on; % Mostra la griglia

% Add legend
legend('show');

hold off

%% Data plotting current
% Combined plot: Tempo vs Errore, Riferimento, and Uscita

% Remove the first 20 samples
data_reduce = data(21:end, :);

figure();
hold on

% Plot Errore
plot(data_reduce(:,1) * 0.001, data_reduce(:,5), '-g', 'DisplayName', 'Errore'); % errore

% Plot Riferimento
plot(data_reduce(:,1) * 0.001, data_reduce(:,6), '-m', 'DisplayName', 'Riferimento'); % riferimento

% Plot Uscita
plot(data_reduce(:,1) * 0.001, data_reduce(:,7), '-b', 'DisplayName', 'Uscita'); % uscita


ylabel('Valore'); % Etichetta dell'asse y
xlabel('Tempo (s)'); % Etichetta dell'asse x
title('Errore, Riferimento e Uscita'); % Titolo del grafico
grid on; % Mostra la griglia

% Add legend
legend('show');

hold off
