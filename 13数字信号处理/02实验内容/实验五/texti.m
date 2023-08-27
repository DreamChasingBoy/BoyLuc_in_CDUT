%导入训练集
%第1列.数学成绩，第2列.语文成绩，第3列.英语成绩
train_data=[140,111,130;
            87,86,87;
            135,121,129;
            141,115,135;
            88,89,87;
            80,89,85;
            125,100,115;
            79,85,82;
            81,88,87];
%样本标签中1表示优秀，2表示良，3表示差
train_lable=[1,3,1,1,3,3,2,3,3]';     
%导入测试集
test_data=[84,72,79];
%计算测试集T与训练集之间的距离
for i=1:size(test_data,2)
d(:,i)=(train_data(:,i)-test_data(:,i)).^2;
end
d=sqrt(sum(d,2));
%计算前k个点所在类别出现的频率
 k=5;  %k的取值一般来说k<训练集数
 [d_sort,index]=sort(d);  
%选取前k个对应的类别、统计前k个类别数
notlike_num=0;
Charmgen_num=0;
Charmgbest_num=0;
for i=1:k
    seclect_front_k_lable(i)=train_lable(index(i));
    if seclect_front_k_lable(i)==1
        notlike_num=notlike_num+1;
    else if seclect_front_k_lable(i)==1
        Charmgen_num=Charmgen_num+1;
    else
       Charmgbest_num=Charmgbest_num+1;
    end
    end
end
%计算类别出现的频率
nolike_fre=notlike_num/k;
disp(strcat('前k个中优秀的频率为：',num2str(nolike_fre)));
Charmgen_fre=Charmgen_num/k;
disp(strcat('前k个中良的频率为：',num2str(Charmgen_fre)));
Charmgbest_fre=Charmgbest_num/k;
disp(strcat('前k个中差的频率为：',num2str(Charmgbest_fre)));

%%预测结果
fre_num=[nolike_fre,Charmgen_fre,Charmgbest_fre];
lable={'优秀','良','差'};
[~,lable_retun_num]=max(fre_num);
disp(strcat('该生学习情况为：',lable{lable_retun_num}))