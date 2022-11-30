#include <iostream>
#include "Vtop.h"
#include "verilated_toplevel.h"
#include "verilator_sim_ctrl.h"


int main(int argc, char **argv) {
  top top;
  VerilatorSimCtrl &simctrl = VerilatorSimCtrl::GetInstance();
  simctrl.SetTop(&top, &top.clk, &top.reset_n, VerilatorSimCtrlFlags::ResetPolarityNegative);
  simctrl.SetInitialResetDelay(200);
  simctrl.SetResetDuration(10);

  std::cout << "Simulation Starting" << std::endl
            << "===================" << std::endl
            << std::endl;

  return simctrl.Exec(argc, argv).first;
}