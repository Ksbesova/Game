/*
 * ThreeStonesGame.cpp
 *
 *  Created on: 19 нояб. 2020 г.
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
			std::cerr<< "Ошибка ввода/вывода" << std::endl;
			exit(1);
		}
		else{
			std::cerr<< "Неверный формат числа!" << std::endl;
			std::cerr.flush();
			return read_int("Игрок, введите число от 1 до 3 ");
		}
	}
	else if (!(input_ss.eof())){
		std::cout<<"Не понятно, что это?"<<std::endl;
		return read_int("Игрок, введите число от 1 до 3 ");
	}
	return result;
}

int main(){
	std::random_device rd; //Датчик случайных чисел
	std::default_random_engine rnd {rd()};
	std::uniform_int_distribution<>rndNum {15, 25};
	std::uniform_int_distribution<>rndKamni {1, 3};
	std::uniform_int_distribution<>rndHod {1, 2};
	int n = rndNum(rnd);
	int hod = rndHod(rnd);

	std::cout<< "Как вас зовут?"<<std::endl;
	std::string name;
	std::getline(std::cin, name);
	std::cout<<name<<", какой уровень игры вы хотите?"<<std::endl;
	std::cout<< "1: Уровень 1"<<std::endl;
	std::cout<< "2: Уровень 2"<<std::endl;
	std::cout<< "3: Уровень 3"<<std::endl;
	int lev;
	lev=read_int("Ваш выбор: ");
	std::cout<<std::endl;

	if (lev==1){
		std::cout<<"На столе "<<n<<" камней"<<std::endl;
		std::cout<<std::endl;
		if (hod==0)
			std::cout<<"Компьютер делает ход..."<<std::endl;
		else
			std::cout<<name<<", ваш ход" << std:: endl;
		while (n>1){
			if (hod==0){
				std::cout<<"Компьютер делает ход..."<<std::endl;
				int k=rndKamni(rnd);
				n-=k;
				std::cout<<"Компьютер взял "<<k<<" камней"<<std::endl;
				std::cout<<std::endl;
				std::cout<< "На столе осталось "<<n<<" камней"<<std::endl;
				std::cout<<std::endl;
				hod=1;
			}
			else{
				std::cout<<name<<", введите число от 1 до 3"<<std::endl;
				int chislo;
				chislo=read_int("");
				while(chislo>3 or chislo<1){
					std::cout<<name<<", вы ввели неверное число"<<std::endl;
					std::cout<<name<<", введите число от 1 до 3"<<std::endl;
					chislo=read_int("");

				};
				n-=chislo;
				std::cout<< "На столе осталось "<<n<<" камней"<<std::endl;
				std::cout<<std::endl;
				hod=0;
			}
		}
		if (hod==0)
			std::cout<<"Проиграл компьютер"<<std::endl;
		else
			std::cout<<name<<", вы проиграли!"<<std::endl;
	}
	else if (lev==2){
		std::cout<<"На столе "<<n<<" камней"<<std::endl;
		std::cout<<std::endl;
		if (hod==0)
			std::cout<<"Компьютер делает ход..."<<std::endl;
		else
			std::cout<<name<<", ваш ход" << std::endl;

		while (n>10){
			if (hod==0){
				std::cout<<"Компьютер делает ход..."<<std::endl;
					int k=rndKamni(rnd);
					n-=k;
					std::cout<<"Компьютер взял "<<k<<" камней"<<std::endl;
					std::cout<<std::endl;
					std::cout<< "На столе осталось "<<n<<" камней"<<std::endl;
					std::cout<<std::endl;
					hod=1;
			}
			else{
				std::cout<<name<<", введите число от 1 до 3:"<<std::endl;
					int chislo;
					chislo=read_int("");
					while(chislo>3 or chislo<1){
						std::cout<<name<<", вы ввели неверное число"<<std::endl;
						std::cout<<name<<", введите число от 1 до 3"<<std::endl;
						chislo=read_int("");

					};
					n-=chislo;
					std::cout<< "На столе осталось "<<n<<" камней"<<std::endl;
					std::cout<<std::endl;
					hod=0;
			}
		}

		while(n>1){
			if (hod==0){
				std::cout<<"Компьютер делает ход..."<<std::endl;
					if (n%4==2){
						std::cout<<"Компьютер взял 1 камень"<<std::endl;
						std::cout<<std::endl;
						n-=1;
					}
					else if (n%4==3){
						std::cout<<"Компьютер взял 3 камня"<<std::endl;
						std::cout<<std::endl;
						n-=2;
					}
					else if (n%4==1){
						int k=rndKamni(rnd);
						n-=k;
						std::cout<<"Компьютер взял "<<k<<" камней"<<std::endl;
						std::cout<<std::endl;
					}
					std::cout<< "На столе осталось "<<n<<" камней"<<std::endl;
					std::cout<<std::endl;
					hod=1;
			}
			else{
				std::cout<<name<<", введите число от 1 до 3:"<<std::endl;
					int chislo;
					chislo=read_int("");
					while(chislo>3 or chislo<1){
						std::cout<<name<<", вы ввели неверное число"<<std::endl;
						std::cout<<name<<", введите число от 1 до 3"<<std::endl;
						chislo=read_int("");

					};
					n-=chislo;
					std::cout<< "На столе осталось "<<n<<" камней"<<std::endl;
					std::cout<<std::endl;
					hod=0;
			}

		}


		if (hod==0)
			std::cout<<"Проиграл компьютер"<<std::endl;
		else
			std::cout<<name<<", вы проиграли!"<<std::endl;

	}
	else{
		std::cout<<"На столе "<<n<<" камней"<<std::endl;
		std::cout<<std::endl;
		if (hod==0)
			std::cout<<"Компьютер делает ход..."<<std::endl;
		else
			std::cout<<name<<", ваш ход" << std:: endl;

		while(n>1){
			if (hod==0){
				std::cout<<"Компьютер делает ход..."<<std::endl;
					if (n%4==2){
						std::cout<<"Компьютер взял 1 камень"<<std::endl;
						std::cout<<std::endl;
						n-=1;
					}
					else if (n%4==3){
						std::cout<<"Компьютер взял 3 камня"<<std::endl;
						std::cout<<std::endl;
						n-=2;
					}
					else if (n%4==1){
						int k=rndKamni(rnd);
						n-=k;
						std::cout<<"Компьютер взял "<<k<<" камней"<<std::endl;
						std::cout<<std::endl;
					}
					std::cout<< "На столе осталось "<<n<<" камней"<<std::endl;
					std::cout<<std::endl;
					hod=1;
			}
			else{
				std::cout<<name<<", введите число от 1 до 3:"<<std::endl;
					int chislo;
					chislo=read_int("");
					while(chislo>3 or chislo<1){
						std::cout<<name<<", вы ввели неверное число"<<std::endl;
						std::cout<<name<<", введите число от 1 до 3"<<std::endl;
						chislo=read_int("");

					};
					n-=chislo;
					std::cout<< "На столе осталось "<<n<<" камней"<<std::endl;
					std::cout<<std::endl;
					hod=0;
			}

		}


		if (hod==0)
			std::cout<<"Проиграл компьютер"<<std::endl;
		else
			std::cout<<name<<", вы проиграли!"<<std::endl;
	}


	return 0;
}


