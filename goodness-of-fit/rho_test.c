//
//
#include<iostream>
#include<fstream>
#include<vector>
#include<valarray>
#include<stdexcept>
using namespace std;

double rho_test(string expf,string thef,const double & chi2)
{
    ifstream expp(expf);
    ifstream thee(thef);
    
    if(expp.fail()||thee.fail())
    {   
        throw std::invalid_argument( "can not find file" );
    }

    vector<double> residuals;
    double x0,y0,error,x,y,residual,chisq=0;
    while(expp>>x0>>y0>>error)
    {
        residual = (y0 - INTERPOLATE1D(x0,thef))/error;
        residuals.push_back(residual);
        chisq += residual * residual;
    }
    expp.close();
    chi2 = chisq;
    std::valarray<double> vresidual(residuals.data(),residuals.size());
    double rho_test = (vresidual * vresidual.shift(1)).sum()/chisq;
    return rho_test;
}



#if 0
int main()
{
    cout<<" -- "<<rho_test("a","b");
}
#endif
