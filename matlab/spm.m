clear all; close all;
for k=[8,9]
    figure(k);
    str = ['sp1e' int2str(k) 'm.txt'];
    f = dlmread(str);
    air = f(:,[1 2]);
    pro = f(:,[1 3]);

    air_seq = air(1,2);
    pro_seq = pro(1,2);
    v = 1;
    for i=2:size(air,1)
        r = air_seq/air(i,2);
        v = [v r];
    end

    w = 1;
    for j=2:size(pro,1)
        s = pro_seq/pro(j,2);
        w = [w s];
    end
    plot(air(:,1),v(:),'-*');
    hold on;
    plot(air(:,1),air(:,1),'r');
    plot(pro(:,1),w(:),'-og');
    legend('MacBook Air','Ideal','MacBook Pro');
    hold off;
    legend('Location','NorthWest');
    str3 = ['Speedup plot for n=10^' int2str(k)];
    title(str3);
    xlabel('p');
    ylabel('Speedup');
    set(k,'Position',[386 91 588 567]);
    str2 = ['sp1e' int2str(k) 'm'];
    print(k,'-depsc','-r300',str2);
    %clear all; close all;
end