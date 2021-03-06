#include "TSPsolution.hpp"

using std::ostream;
using std::string;
using std::vector;

TSPsolution::TSPsolution(const double obj, const unsigned int N,
                         const vector<double>& varmap,
                         const vector<string>& namemap, const string& stour,
                         const vector<vertex>& vetour, int impr_iter)
    : varVals(varmap),
      nameMap(namemap),
      objVal(obj),
      N(N),
      stour(stour),
      vtour(vetour),
      improving_iterations_lk(impr_iter) {}
ostream& operator<<(ostream& out, const TSPsolution& sol) {
  out << "*************************************\n";
  out << "Size: " << sol.N << "\nObj. value: " << sol.objVal << "\n";
  if (sol.improving_iterations_lk)
    out << "Improving iterations: " << sol.improving_iterations_lk << "\n";
  if (!sol.stour.empty()) out << "Tour: " << sol.stour << "\n";
  // NOTE: Decomment this to see variale assignment in cplex log file
  // if (!(sol.varVals.empty() && sol.nameMap.empty())) {
  //   for (unsigned int i = 0; i < sol.varVals.size(); ++i)
  //     out << sol.nameMap[i] << " : " << sol.varVals[i] << "\n";
  // }
  return out << std::endl;
}