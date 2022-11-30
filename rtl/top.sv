module top(
  input logic clk,
  input logic reset_n,
  output logic [7:0] count
);

  logic [7:0] count_q;

  always_ff @(posedge clk or negedge reset_n) begin
    if (!reset_n) begin
      count_q <= '0;
    end else begin
      count_q <= count_q + 8'h1;
    end
  end

  assign count = count_q;


endmodule

