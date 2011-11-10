%for b=[2,32,64,256]
    b = int2str(32);
    close all;
    str = ['abyssos-' b '-get'];
    str2 = [str '.txt'];
    pts = dlmread(str2);
    n = size(pts,1);
    B = pts(:,2);
    C = [];
    for i=2:n
        C = [C; i-1 B(i)];
    end
    c1 = C(:,1);
    c2 = C(:,2);
%scatter(C(:,1),C(:,2),'*');
%figure;
    createFit(c1,c2);
    str3 = [str '.eps'];
    legend('Location','SouthEast');
    set(1,'Position',[386 91 588 567]);
    print(1,'-depsc','-r300',str3);
%end