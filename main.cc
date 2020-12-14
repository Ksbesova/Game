/*
 * ThreeStonesGame.cpp
 *
 *  Created on: 19 ����. 2020 �.
 *      Author: ksbesova
 */

#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include <chrono>


int read_int(const char * prompt)	{
	int result;
	std::string input;
	std::cout<< prompt;
	std::getline(std::cin, input);
	std::stringstream input_ss {input};
	input_ss>> result;
	if (input_ss.fail()){
		if (std::cin.eof()){
			std::cerr<< "������ �����/������" << std::endl;
			exit(1);
		}
		else{
			std::cerr<< "�������� ������ �����!" << std::endl;
			std::cerr.flush();
			return read_int("�����, ������� ����� �� 1 �� 3 ");
		}
	}
	else if (!(input_ss.eof())){
		std::cout<<"�� �������, ��� ���?"<<std::endl;
		return read_int("�����, ������� ����� �� 1 �� 3 ");
	}
	return result;
}

int main(){
	std::random_device rd; //������ ��������� �����
	std::default_random_engine rnd {rd()};
	std::uniform_int_distribution<>rndNum {15, 25};
	std::uniform_int_distribution<>rndKamni {1, 3};
	std::uniform_int_distribution<>rndHod {1, 2};
	int n = rndNum(rnd);
	int hod = rndHod(rnd);

	std::cout<< "��� ��� �����?"<<std::endl;
	std::string name;
	std::getline(std::cin, name);
	std::cout<<name<<", ����� ������� ���� �� ������?"<<std::endl;
	std::cout<< "1: ������� 1"<<std::endl;
	std::cout<< "2: ������� 2"<<std::endl;
	std::cout<< "3: ������� 3"<<std::endl;
	int lev;
	lev=read_int("��� �����: ");
	std::cout<<std::endl;

	if (lev==1){
		std::cout<<"�� ����� "<<n<<" ������"<<std::endl;
		std::cout<<std::endl;
		if (hod==0)
			std::cout<<"��������� ������ ���..."<<std::endl;
		else
			std::cout<<name<<", ��� ���" << std:: endl;
		while (n>1){
			if (hod==0){
				std::cout<<"��������� ������ ���..."<<std::endl;
				int k=rndKamni(rnd);
				n-=k;
				std::cout<<"��������� ���� "<<k<<" ������"<<std::endl;
				std::cout<<std::endl;
				std::cout<< "�� ����� �������� "<<n<<" ������"<<std::endl;
				std::cout<<std::endl;
				hod=1;
			}
			else{
				std::cout<<name<<", ������� ����� �� 1 �� 3"<<std::endl;
				int chislo;
				chislo=read_int("");
				while(chislo>3 or chislo<1){
					std::cout<<name<<", �� ����� �������� �����"<<std::endl;
					std::cout<<name<<", ������� ����� �� 1 �� 3"<<std::endl;
					chislo=read_int("");

				};
				n-=chislo;
				std::cout<< "�� ����� �������� "<<n<<" ������"<<std::endl;
				std::cout<<std::endl;
				hod=0;
			}
		}
		if (hod==0)
			std::cout<<"�������� ���������"<<std::endl;
		else
			std::cout<<name<<", �� ���������!"<<std::endl;
	}
	else if (lev==2){
		std::cout<<"�� ����� "<<n<<" ������"<<std::endl;
		std::cout<<std::endl;
		if (hod==0)
			std::cout<<"��������� ������ ���..."<<std::endl;
		else
			std::cout<<name<<", ��� ���" << std::endl;

		while (n>10){
			if (hod==0){
				std::cout<<"��������� ������ ���..."<<std::endl;
					int k=rndKamni(rnd);
					n-=k;
					std::cout<<"��������� ���� "<<k<<" ������"<<std::endl;
					std::cout<<std::endl;
					std::cout<< "�� ����� �������� "<<n<<" ������"<<std::endl;
					std::cout<<std::endl;
					hod=1;
			}
			else{
				std::cout<<name<<", ������� ����� �� 1 �� 3:"<<std::endl;
					int chislo;
					chislo=read_int("");
					while(chislo>3 or chislo<1){
						std::cout<<name<<", �� ����� �������� �����"<<std::endl;
						std::cout<<name<<", ������� ����� �� 1 �� 3"<<std::endl;
						chislo=read_int("");

					};
					n-=chislo;
					std::cout<< "�� ����� �������� "<<n<<" ������"<<std::endl;
					std::cout<<std::endl;
					hod=0;
			}
		}

		while(n>1){
			if (hod==0){
				std::cout<<"��������� ������ ���..."<<std::endl;
					if (n%4==2){
						std::cout<<"��������� ���� 1 ������"<<std::endl;
						std::cout<<std::endl;
						n-=1;
					}
					else if (n%4==3){
						std::cout<<"��������� ���� 3 �����"<<std::endl;
						std::cout<<std::endl;
						n-=2;
					}
					else if (n%4==1){
						int k=rndKamni(rnd);
						n-=k;
						std::cout<<"��������� ���� "<<k<<" ������"<<std::endl;
						std::cout<<std::endl;
					}
					std::cout<< "�� ����� �������� "<<n<<" ������"<<std::endl;
					std::cout<<std::endl;
					hod=1;
			}
			else{
				std::cout<<name<<", ������� ����� �� 1 �� 3:"<<std::endl;
					int chislo;
					chislo=read_int("");
					while(chislo>3 or chislo<1){
						std::cout<<name<<", �� ����� �������� �����"<<std::endl;
						std::cout<<name<<", ������� ����� �� 1 �� 3"<<std::endl;
						chislo=read_int("");

					};
					n-=chislo;
					std::cout<< "�� ����� �������� "<<n<<" ������"<<std::endl;
					std::cout<<std::endl;
					hod=0;
			}

		}


		if (hod==0)
			std::cout<<"�������� ���������"<<std::endl;
		else
			std::cout<<name<<", �� ���������!"<<std::endl;

	}
	else{
		std::cout<<"�� ����� "<<n<<" ������"<<std::endl;
		std::cout<<std::endl;
		if (hod==0)
			std::cout<<"��������� ������ ���..."<<std::endl;
		else
			std::cout<<name<<", ��� ���" << std:: endl;

		while(n>1){
			if (hod==0){
				std::cout<<"��������� ������ ���..."<<std::endl;
					if (n%4==2){
						std::cout<<"��������� ���� 1 ������"<<std::endl;
						std::cout<<std::endl;
						n-=1;
					}
					else if (n%4==3){
						std::cout<<"��������� ���� 3 �����"<<std::endl;
						std::cout<<std::endl;
						n-=2;
					}
					else if (n%4==1){
						int k=rndKamni(rnd);
						n-=k;
						std::cout<<"��������� ���� "<<k<<" ������"<<std::endl;
						std::cout<<std::endl;
					}
					std::cout<< "�� ����� �������� "<<n<<" ������"<<std::endl;
					std::cout<<std::endl;
					hod=1;
			}
			else{
				std::cout<<name<<", ������� ����� �� 1 �� 3:"<<std::endl;
					int chislo;
					chislo=read_int("");
					while(chislo>3 or chislo<1){
						std::cout<<name<<", �� ����� �������� �����"<<std::endl;
						std::cout<<name<<", ������� ����� �� 1 �� 3"<<std::endl;
						chislo=read_int("");

					};
					n-=chislo;
					std::cout<< "�� ����� �������� "<<n<<" ������"<<std::endl;
					std::cout<<std::endl;
					hod=0;
			}

		}


		if (hod==0)
			std::cout<<"�������� ���������"<<std::endl;
		else
			std::cout<<name<<", �� ���������!"<<std::endl;
	}


	return 0;
}


