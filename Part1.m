clc; clear; warning('off');
f=146.502; %cutoff frequency
w=2*pi*f;  %cutoff freq in radians
dt= 1.15e-4;
s =sym(1);
omega = logspace(-3, .4969, 1001);
Z = exp(1i*omega);
Zexact=log(Z)/dt;
Ztustin=(2./dt).*((Z-1)./(Z+1));
poles=[w*exp((i*5*pi)./8),w*exp((i*7*pi)./8),w*exp((i*9*pi)./8),w*exp((i*11*pi)./8)]; %poles of system
xfer=1./((s-poles(1))*(s-poles(2))*(s-poles(3))*(s-poles(4))); %DC gain
mult=5/abs(xfer); %DC Gain multiplier
HdExactNum= 9.3502e+15;
HdExactDen= (Zexact+(6075+2516i)).*(Zexact+(6075-2516i)).*(Zexact+(2516+6075i)).*(Zexact+(2516-6075i));
HdExactE= HdExactNum ./ HdExactDen;
HdNum= 9.3502e+15;
HdDen=(Ztustin+(6075+2516i)).*(Ztustin+(6075-2516i)).*(Ztustin+(2516+6075i)).*(Ztustin+(2516-6075i));
HdTustin=HdNum ./ HdDen;


Hc = zpk([],poles,double(mult));
disp("Project Part 1, Part A")
Hc
DCGAIN = dcgain(Hc)
disp("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")

disp("Project Part 1, Part B");
% tf(HdExactNum,HdExactDen,dt)



disp("Project Part 1, Part C")
%plot(omega/dt, (abs(HdE)-abs(HdExactE)))
%semilogx(omega/dt, 20*log10(abs(HdExactE)))
%semilogx(omega/dt, 20*log10(abs(HdTustin)))
 figure(1)
 %plot(omega/dt, abs((abs(HdTustin)-(abs(HdExactE)))))
 semilogx(omega/dt,20*log10(HdExactE))
 title('H_c(Z)')
 xlim([1 9000])
 ylabel('Amplitude')
 xlabel('Frequency')

% figure
% bode(Hc)
% title('H_c(S)')
% ylabel('Amplitude')
% xlabel('Frequency')