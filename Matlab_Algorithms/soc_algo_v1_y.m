
% set = "https://www.kaggle.com/datasets/officialdatasets/battery-soc-dataset";
% set_save = websave("dataset.csv",set);
% set_read = readtable("dataset.csv");

%EFFICINECY 
%DATASHEET SE READ KARKE USKE GRAPH KLE ACCORDING CHANGES 

Ns = 72;
Np = 5;
% 
q_nom = 3.6;
q_nom_cells = q_nom*3600 ; %capacity in couloumbs
q_nom_pack = q_nom_cells*Np;

SoC_initial = 1;
dt = 1e-2;
e = 0.989765;

time = 0:dt:360000;
discharge_curr_pack = 10 * ones(size(time));

SoC = zeros(size(time));
cap_cell = zeros(size(time));             
V_cell = zeros(size(time));
V_pack = zeros(size(time));

SoC(1) = SoC_initial;

%discharge temperature characterstics of mollicel p45b
capacity_curve = [   0  500 1000 1500 2000 2500 3000 3500 4000 4400 ];  
voltage_curve_23C = [4.2 4.05 3.95 3.85 3.75 3.65 3.55 3.45 3.30 2.50];

for i=2:length(time)
    delta_q = discharge_curr_pack(i)*dt;
    %coulomb counting 
    SoC(i) = SoC(i-1) - ((delta_q / q_nom_pack)*e) ;
    SoC(i) = max(0, min(1, SoC(i)));

    i_cell= discharge_curr_pack(i)/Np;
    cap_cell(i)= cap_cell(i-1) - i_cell*dt/3600*1000;

    V_cell(i) = interp1(capacity_curve, voltage_curve_23C, cap_cell(i), 'linear', 'extrap');
    V_pack(i) = V_cell(i) * Ns;
end

figure;
subplot(3,1,1)
plot(time, SoC*100)
ylabel('SoC (%)')
title('Pack SoC (72S×5P)')

subplot(3,1,2)
plot(time, cap_cell)
ylabel('Cell capacity used (mAh)')
title('Per-cell mAh used')

subplot(3,1,3)
plot(time, V_pack)
xlabel('Time (s)')
ylabel('Pack Voltage (V)')
title('Estimated Pack Voltage @ 23 °C')
grid on;