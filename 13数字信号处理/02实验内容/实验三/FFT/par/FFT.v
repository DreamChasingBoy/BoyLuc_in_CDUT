module FFT(
	input clk,
	input rst_n,
	input data_in_en,
	
	
	output reg data_out_en,
	output reg signed [4:0] fft_data_out_re0,
	output reg signed [4:0] fft_data_out_im0,
	output reg signed [4:0] fft_data_out_re1,
	output reg signed [4:0] fft_data_out_im1,
	output reg signed [4:0] fft_data_out_re2,
	output reg signed [4:0] fft_data_out_im2,
	output reg signed [4:0] fft_data_out_re3,
	output reg signed [4:0] fft_data_out_im3,
	
	output reg signed [4:0] ifft_data_out_re0,
	output reg signed [4:0] ifft_data_out_im0,
	output reg signed [4:0] ifft_data_out_re1,
	output reg signed [4:0] ifft_data_out_im1,
	output reg signed [4:0] ifft_data_out_re2,
	output reg signed [4:0] ifft_data_out_im2,
	output reg signed [4:0] ifft_data_out_re3,
	output reg signed [4:0] ifft_data_out_im3
);
//输入
reg signed [4:0] data_in_re0;
reg signed [4:0] data_in_im0;
reg signed [4:0] data_in_re1;
reg signed [4:0] data_in_im1;
reg signed [4:0] data_in_re2;
reg signed [4:0] data_in_im2;
reg signed [4:0] data_in_re3;
reg signed [4:0] data_in_im3;
//一级
reg fft1_en;
reg signed [10:0] fft1_re0;
reg signed [10:0] fft1_im0;
reg signed [10:0] fft1_re1;
reg signed [10:0] fft1_im1;
reg signed [10:0] fft1_re2;
reg signed [10:0] fft1_im2;
reg signed [10:0] fft1_re3;
reg signed [10:0] fft1_im3;
initial begin//赋初值
	data_in_re0<=-5'd2;
	data_in_im0<=5'd1;
	data_in_re1<=5'd4;
	data_in_im1<=5'd2;
	data_in_re2<=5'd3;
	data_in_im2<=5'd0;
	data_in_re3<=5'd4;
	data_in_im3<=5'd0;
end
always @(posedge clk or negedge rst_n)begin
	if(!rst_n)begin
		fft1_en<=1'b0;
		fft1_re0<=1'b0;
		fft1_im0<=1'b0;
		fft1_re1<=1'b0;
		fft1_im1<=1'b0;
		fft1_re2<=1'b0;
		fft1_im2<=1'b0;
		fft1_re3<=1'b0;
		fft1_im3<=1'b0;
	end
	else if(data_in_en)begin
		fft1_re0<=data_in_re0+data_in_re2;
		fft1_im0<=data_in_im0+data_in_im2;
		fft1_re1<=data_in_re0-data_in_re2;
		fft1_im1<=data_in_im0-data_in_im2;
		fft1_re2<=data_in_re1+data_in_re3;
		fft1_im2<=data_in_im1+data_in_im3;
		fft1_re3<=data_in_re1-data_in_re3;
		fft1_im3<=data_in_im1-data_in_im3;
		fft1_en<=1'b1;
	end
	else
		fft1_en<=1'b0;
end
//二级
reg ifft1_en;
reg signed [10:0] fft2_re0;
reg signed [10:0] fft2_im0;
reg signed [10:0] fft2_re1;
reg signed [10:0] fft2_im1;
reg signed [10:0] fft2_re2;
reg signed [10:0] fft2_im2;
reg signed [10:0] fft2_re3;
reg signed [10:0] fft2_im3;
always @(posedge clk or negedge rst_n)begin
	if(!rst_n)begin
		fft2_re0<=1'b0;
		fft2_im0<=1'b0;
		fft2_re1<=1'b0;
		fft2_im1<=1'b0;
		fft2_re2<=1'b0;
		fft2_im2<=1'b0;
		fft2_re3<=1'b0;
		fft2_im3<=1'b0;
	end
	else if(fft1_en)begin
		fft2_re0<=fft1_re0+fft1_re2;
		fft2_im0<=fft1_im0+fft1_im2;//x0
		fft2_re1<=fft1_re1+fft1_im3;
		fft2_im1<=fft1_im1-fft1_re3;
		fft2_re2<=fft1_re0-fft1_re2;
		fft2_im2<=fft1_im0-fft1_im2;
		fft2_re3<=fft1_re1-fft1_im3;
		fft2_im3<=fft1_im1+fft1_re3;
		ifft1_en<=1'b1;
	end
	else
		ifft1_en<=1'b0;
end

//ifft
reg ifft2_en;
reg signed [10:0] ifft1_re0;
reg signed [10:0] ifft1_im0;
reg signed [10:0] ifft1_re1;
reg signed [10:0] ifft1_im1;
reg signed [10:0] ifft1_re2;
reg signed [10:0] ifft1_im2;
reg signed [10:0] ifft1_re3;
reg signed [10:0] ifft1_im3;
always @(posedge clk or negedge rst_n)begin
	if(!rst_n)begin
		ifft2_en<=1'b0;
		ifft1_re0<=1'b0;
		ifft1_im0<=1'b0;
		ifft1_re1<=1'b0;
		ifft1_im1<=1'b0;
		ifft1_re2<=1'b0;
		ifft1_im2<=1'b0;
		ifft1_re3<=1'b0;
		ifft1_im3<=1'b0;
	end
	else if(ifft1_en)begin
		ifft1_re0<=fft2_re0+fft2_re2;
		ifft1_im0<=fft2_im0+fft2_im2;
		ifft1_re1<=fft2_re0-fft2_re2;
		ifft1_im1<=fft2_im0-fft2_im2;
		ifft1_re2<=fft2_re1+fft2_re3;
		ifft1_im2<=fft2_im1+fft2_im3;
		ifft1_re3<=fft2_re1-fft2_re3;
		ifft1_im3<=fft2_im1-fft2_im3;
		ifft2_en<=1'b1;
	end
	else
		ifft2_en<=1'b0;
end

reg signed [10:0] ifft2_re0;
reg signed [10:0] ifft2_im0;
reg signed [10:0] ifft2_re1;
reg signed [10:0] ifft2_im1;
reg signed [10:0] ifft2_re2;
reg signed [10:0] ifft2_im2;
reg signed [10:0] ifft2_re3;
reg signed [10:0] ifft2_im3;
always @(posedge clk or negedge rst_n)begin
	if(!rst_n)begin
		ifft2_re0<=1'b0;
		ifft2_im0<=1'b0;
		ifft2_re1<=1'b0;
		ifft2_im1<=1'b0;
		ifft2_re2<=1'b0;
		ifft2_im2<=1'b0;
		ifft2_re3<=1'b0;
		ifft2_im3<=1'b0;
	end
	else if(ifft2_en)begin
		ifft2_re0<=ifft1_re0+ifft1_re2;
		ifft2_im0<=ifft1_im0+ifft1_im2;
		ifft2_re1<=(ifft1_re1+ifft1_im3);
		ifft2_im1<=(-ifft1_re3+ifft1_im1);
		ifft2_re2<=ifft1_re0-ifft1_re2;
		ifft2_im2<=ifft1_im0-ifft1_im2;
		ifft2_re3<=(ifft1_re1-ifft1_im3);
		ifft2_im3<=(ifft1_im1+ifft1_re3);
		data_out_en<=1'b1;
	end
	else
		data_out_en<=1'b0;
end
//赋值
always @(posedge clk or negedge rst_n)begin
	if(!rst_n)begin
		fft_data_out_re0<=1'b0;
		fft_data_out_im0<=1'b0;
		fft_data_out_re1<=1'b0;
		fft_data_out_im1<=1'b0;
		fft_data_out_re2<=1'b0;
		fft_data_out_im2<=1'b0;
		fft_data_out_re3<=1'b0;
		fft_data_out_im3<=1'b0;
	end
	else if(data_out_en)begin
		fft_data_out_re0<=fft2_re0;
		fft_data_out_im0<=fft2_im0;
		fft_data_out_re1<=fft2_re1;
		fft_data_out_im1<=fft2_im1;
		fft_data_out_re2<=fft2_re2;
		fft_data_out_im2<=fft2_im2;
		fft_data_out_re3<=fft2_re3;
		fft_data_out_im3<=fft2_im3;
		
		ifft_data_out_re0<=ifft2_re0/4'd4;
		ifft_data_out_im0<=ifft2_im0/4'd4;
		ifft_data_out_re1<=ifft2_re1/4'd4;
		ifft_data_out_im1<=ifft2_im1/4'd4;
		ifft_data_out_re2<=ifft2_re2/4'd4;
		ifft_data_out_im2<=ifft2_im2/4'd4;
		ifft_data_out_re3<=ifft2_re3/4'd4;
		ifft_data_out_im3<=ifft2_im3/4'd4;
	end
	else begin
		fft_data_out_re0<=fft_data_out_re0;
		fft_data_out_im0<=fft_data_out_im0;
		fft_data_out_re1<=fft_data_out_re1;
		fft_data_out_im1<=fft_data_out_im1;
		fft_data_out_re2<=fft_data_out_re2;
		fft_data_out_im2<=fft_data_out_im2;
		fft_data_out_re3<=fft_data_out_re3;
		fft_data_out_im3<=fft_data_out_im3;
		
		
		ifft_data_out_re0<=ifft_data_out_re0;
		ifft_data_out_im0<=ifft_data_out_im0;
		ifft_data_out_re1<=ifft_data_out_re1;
		ifft_data_out_im1<=ifft_data_out_im1;
		ifft_data_out_re2<=ifft_data_out_re2;
		ifft_data_out_im2<=ifft_data_out_im2;
		ifft_data_out_re3<=ifft_data_out_re3;
		ifft_data_out_im3<=ifft_data_out_im3;
	end
end
endmodule
