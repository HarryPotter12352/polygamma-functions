#include<iostream>
#include<complex>

std::complex<double> gamma_integrand(std::complex<double> t, std::complex<double> z){
    if (std::abs(t) < 1e-7){
        // std::cout << "Value of t too small. Returning 0" << std::endl;
        return std::complex<double>(0,0);
    }
    return std::pow(t, z-1.0)*std::exp(-t);
}

std::complex<double> gamma(std::complex<double> z, double lower_limit = 1e-10, double upper_limit = 1e5, double steps = 1e5){
    double step_size = (upper_limit - lower_limit)/steps;
    std::complex<double> integral(0,0);

    integral += 0.5 * (gamma_integrand(std::complex<double>(lower_limit, 0), z) + gamma_integrand(std::complex<double>(upper_limit, 0), z));

    for (int i = 1; i<= steps; i++){
        double t = lower_limit + i * step_size;
        integral += gamma_integrand(std::complex<double>(t, 0), z);
    }
    integral *= step_size;
    return integral;
}

std::complex<double> hurwitz_zeta(int s, std::complex<double> a) {
    if (s<=1){
        std::cout << "Invalid of s. s must be greater than 1" << std::endl;
        return std::complex<double>(0,0);
    }
    double upper_limit = 1e5; 
    std::complex<double> result(0, 0);

    for (int n = 0; n <= upper_limit; n++) {
        std::complex<double> term = std::pow(std::complex<double>(n,0) + a, -s); 
        result += term;
    }

    return result;
}

std::complex<double> polygamma(int n, std::complex<double> z){
    return std::pow(-1, n+1)*gamma(n+1)*hurwitz_zeta(n+1,z);
}