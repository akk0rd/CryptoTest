#include <boost/math/distributions/normal.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

#define COUNT_NUM 256 
#define l 255

int main(int argc, char* argv[])
{	
	std::ifstream input;
	input.open(argv[1]);

	std::vector<int> dest;
	int value;
	input >> value;
	size_t M = 0;
	if ( std::cin ) 
	{
    		dest.push_back( value );
    		char separator;
    		while ( input >> separator >> value && separator == ',' )
		{
        		dest.push_back( value );
			M++;
		}
	}
	int res[COUNT_NUM] = {0};
	for(auto i = dest.begin(); i!=dest.end();i++)
	{
		res[*i]++;
	}
	double hi_quadr = 0.0;
	const int n_j = M/COUNT_NUM;
	for(size_t i = 0;i < COUNT_NUM; i++)
	{
		if(n_j != 0)
		{
			hi_quadr += pow((res[i] - n_j),2)/n_j;
		}
	} 
	std::cout << "hi quadro: " << (int)hi_quadr; 
	
	std::cout << "Input alpha: ";
	double alpha;
	std::cout << std::endl;
	std::cin >> alpha;
	boost::math::normal dist(0.0, 1.0);
	double Z = quantile(dist, 1 - alpha);
	double hiQuAlph = sqrt(2*l)*Z + l;
	std::cout << "hi quadro 1-alpha: " << hiQuAlph << std::endl;
	if(hi_quadr <= hiQuAlph) 
		std::cout << "Good gipotez" << std::endl;
	else
		std::cout << "Bad Gipotez" << std::endl;



	int res2[COUNT_NUM][COUNT_NUM] = {0};
	for(auto i = dest.begin(); i!=dest.end(); i++)
	{
		int x = *i;
		int y = *++i;
		res2[x][y]++;
		if(i == dest.end()) break;
		
	}
	int N = M/2;
	double sum=0;
	for(size_t i=0; i < COUNT_NUM;i++)
	{
		for(size_t j=0; j < COUNT_NUM; j++)
		{
			int v_i = 0, a_j = 0;
			for(size_t k = 0; k < COUNT_NUM; k++)
			{
				v_i += res2[i][k];
				a_j += res2[k][j];
			}
			if(v_i != 0 && a_j != 0 && res2[i][j] != 0)
			{
				sum += pow(res2[i][j],2) /(double)(v_i*a_j);
			}
		}
		
	}
	hi_quadr = N * (sum -1);
	int L = pow(l,2);
	hiQuAlph = sqrt(2*L)*Z+L;
	std::cout << "hi quadro: " << hi_quadr<<std::endl;
	std::cout << "hi quadro 1-alpha: " << hiQuAlph << std::endl;
        if(hi_quadr <= hiQuAlph)
                std::cout << "Good gipotez" << std::endl;
        else
                std::cout << "Bad Gipotez" << std::endl;

	std::cout << "INPUT R:  ";
	int r;
	std::cin >> r;
	std::cout << std::endl;
	int m = M/r;
	int n = r * m;
	int res3[COUNT_NUM][4*COUNT_NUM] = {0};
	int count = 0;
	for(auto i = dest.begin();i != dest.end();i++)
	{
		int temp = (int)(count / m);
		res3[*i][temp]++;
	}
	sum = 0;
	for(size_t i = 0; i < COUNT_NUM; i++)
	{
		for(size_t j = 0; j < r; j++)
		{
			if(res[i] != 0 && res3[i][j] != 0)
			{
				sum += pow(res3[i][j],2) / (double)(res[i] * m);
			}
		}	
	}
	L = l*(r-1);
	hi_quadr =N * (sum -1)/10;
        hiQuAlph = sqrt(2*L)*Z+L;
        std::cout << "hi quadro: " << (long unsigned int)hi_quadr<<std::endl;
        std::cout << "hi quadro 1-alpha: " << (int)hiQuAlph << std::endl;
        if(hi_quadr <= hiQuAlph)
                std::cout << "Good gipotez" << std::endl;
        else
                std::cout << "Bad Gipotez" << std::endl;

	return 0;
}
