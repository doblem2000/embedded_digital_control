function [T,tau] = AreasMethod(step_response, t, y_ss)
    y=step_response;

    n=length(y);

    S1=0;
    
    for j=1:n-1;
        S1 = S1+(y_ss-y(j))*(t(j+1)-t(j));
    end 
    
    index_n = find(t < S1/y_ss);
    
    S2=0;
    
    for k=1:length(index_n)
    
        S2 = S2 + y(k)*(t(k+1)-t(k));
    end
    
    syms T tau
    % Definizione delle equazioni
    
    eq = +S1 - y_ss*(tau+T);
    eq2 = +S2 - (y_ss*T)/exp(1);
    
    % Risoluzione del sistema di equazioni
    sol = solve([eq,eq2], [T, tau]);
    
    T_sol =  double(sol.T)
    tau_sol = double(sol.tau)
    
    s = tf('s')
    
    T = T_sol;
    tau = tau_sol;
end