#include <iostream>
#include <vector>
#include <numbers>
using namespace std;

int main()
{
	const double PI = 3.141592653589793;
	int nSamplesND = 200;

	int n;
	cout << "Introduce the number of samples BN: ";
	cin >> n;

	double nMean, nVar;
	cout << "Introduce mean of Normal distribution: ";
	cin >> nMean;
	cout << "Introduce variance of Normal distribution: ";
	cin >> nVar;
	
	//Vectors save p(x=k) for binomial distribution and samples of normal distribution
	vector<double> bProb(n + 1);
	vector<double> nProb(nSamplesND);

	//save errors 
	vector <double> listErrors(n + 1);

	//calculate n factorial
	int nfactorial = n;
	for (int i = n - 1; i > 0; i--) {
		nfactorial *= i;
	}

	//calculate probability success
	double kProb = 0;
	for (int k = 0; k < n + 1; k++) {
			
		//k factorial - success 
		int kfactorial = k;
		for (int z = k - 1; z > 0; z--) {
			kfactorial *= z;
		}
		if (kfactorial == 0) kfactorial = 1;

		//q factorial - reject
		int qfactorial = n - k;
		for (int z = (n - k - 1); z > 0; z--) {
			qfactorial *= z;
		}
		if (qfactorial == 0) qfactorial = 1;

		//Calculate probability 
		kProb = (nfactorial / (kfactorial * qfactorial)) * pow(0.5, k) * pow(0.5, n - k);

		//save to vector
		bProb[k] = kProb;

	}

	//Output all sucess probabilities
	/*
	cout << "The probibailities of Binomial Distribution are: \n";
	for (int i = 0; i < n + 1; i++) {
		cout << bProb[i];
		if (i<n) {
			cout << " - ";
		}
	}
	cout << "\n";
	*/

	//Calculate samples of Normal distribution
	for (int i = 0; i < nSamplesND; i++) {
		nProb[i] = (1 / (sqrt(nVar * 2 * PI))) * exp(-0.5 * pow(((double)i - nMean) / nVar, 2));
	}

	//Output all values N dist.
	/*
	cout << "The samples of the normal distribution are: \n";
	for (int i = 0; i < n + 1; i++) {
		cout << nProb[i];
		if (i < n) cout << " - ";
	}
	cout << "\n";
	*/

	//Calculate mean square error - MSQ
	double msq = 0;
	int stepGroup = nSamplesND / n;
	for (int i = 0; i < nSamplesND; i++) {
		
		int step = i / stepGroup;
		double aux_diff = bProb[step] - nProb[i];
		msq += aux_diff * aux_diff;


	}
	msq /= nSamplesND;

	//Output mean square error 
	cout << "The mean square error is: " << msq << "\n";


}
