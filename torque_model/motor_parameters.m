%% Motor parameters
k_t = 1.32 % N*m/A
R_a = 4.8 % Ohm
k_e = 1.32 % V*s/rad
L_a = 2.3/1000  % mH
G_v=1

%Model 
s=tf("s")
G= 1 /(s*L_a + R_a)

