#include <iostream>
#include <math.h>
#include <list>
#include <algorithm>
#include <cctype>
//#include <map>
using namespace std;
int mode = 0;
class Enemy {
private:
	string name;
	short relation = 0;
public:
	/*Enemy(string name) {
		this->name = name;
	}*/
	~Enemy() {
		std::cout << "Player " << name << " deleted" << std::endl;
	}
	short get_relation() {
		return relation;
	}
	void increase_relation(short appreciation) {
		relation += appreciation;
	}
	string generate_name() {
		string names[] = { "Александр", "Михаил", "Максим", "Лев", "Марк", "Артём", "Иван", "Матвей", "Дмитрий", "Даниил" };
		name = names[rand() % 10];
		return name;
	}

	void set_name(string name) {
		this->name = name;
	}
	string get_name() {
		return name;
	}
};

class Player {
private:
	string name;
	short relation = 0;
public:
	/*Player(string name) {
		this->name = name;
	}*/
	~Player() {
		std::cout << "Player " << name << " deleted" << std::endl;
	}
	short get_relation() {
		return relation;
	}
	void increase_relation(short appreciation) {
		relation += appreciation;
	}
	void set_name(string name) {
		this->name = name;
	}
	string get_name() {
		return name;
	}
};
class Lover {

public:
	/*Lover(string name, short preferences[] = {}) {
		this->preferences = preferences;
		this->name = name;
	}*/
	~Lover()
	{
		std::cout << "Lover " << name << " deleted" << std::endl;
	}

	short appreciation(/*short& relation,*/ int act, short a_relation[]) {
		//relation += a_relation[act] + prefs[act];
		if (mode == 0) {
			if (preferences[act] > 0)
				//cout << name << ": "<< "How kind of you!" << endl;
				cout << name << ": " << "О, как это мило с твоей стороны" << endl;
			else
				//cout << name << ": " << "I don't like it!" << endl;
				cout << name << ": " << "Я не люблю это!" << endl;
		}
		else if (mode == 1) {
			if (preferences[act] > 0)
				cout << name << ": " << "Ух, как круто!" << endl;
			else
				cout << name << ": " << "Фу! Долой!" << endl;
		}
		return a_relation[act] + preferences[act];
	}
	void generate_character() {
		srand(time(NULL));
		for (size_t i = 0; i < 6; i++)
		{
			preferences[i] = (rand() % 200) - 99;
		}
	}
	string generate_name() {
		string names[]{
			"София",
			"Мария",
			"Анна",
			"Ева",
			"Виктория",
			"Алиса",
			"Полина",
			"Александра",
			"Елизавета",
			"Варвара"
		};
		name = names[rand() % 10];
		return name;
	}
	void set_name(string name) {
		this->name = name;
	}
	string get_name() {
		return name;
	}
private:
	short preferences[6];
	string name;
};

bool findValue(const list<int>& data, int value)
{
	auto result{ std::find(begin(data), end(data), value) };
	if (result == end(data))
		return false;
	else
		return true;
}
//void generate_character(short preferences[]) {
//	srand(time(NULL));
//	for (size_t i = 0; i < 6; i++)
//	{
//		preferences[i] = (rand() % 200) - 99;
//	}
//}
int main() {
	setlocale(LC_ALL, "");
	srand(time(NULL));
	string *actions = 0;
	string love_actions[] = { "Подарить цветы", "Поставить лайк", "Сходить в кино", "Сходить в ресторан", "Захаживать в гости", "Поиграть вместе" }; 
	string politic_actions[] = {
		"Защита окружающей среды",
		"Регулирование финансовых рынков",
		"Реформы здравоохранения и социальной защиты",
		"Программы поддержки образования и науки",
		"Законодательство направленное на улучшение экономической ситуации и создания новых рабочих мест",
		"Агрессивная внешняя политика",
		"Принятие несправедливых и дискриминационных законов или политик",
		"Манипуляции выборами и подрыв демократических процессов",
		"Игнорирование прав граждан и ограничение свободы слова и собраний",
		"Коррупция и злоупотребление полномочиями для личных выгод",

	};
	//{ "Give flowers", "Like", "Go to the cinema", "Go to a restaurant", "Come visit", "Play together"};

	short* actions_relation = 0;
	short love_actions_relation[] = { 10, 5, 25, 50, 20, 15 }; //-10, 15,  5, 5, -30, 35
	short politic_actions_relation[] = { 10,25,50,15,75,7,5,5,2,1 };
	//short preferences[6]; // = { -20, 10, -20, -45,-50, 20 };
	/*map<string, short> actions{
		{"Подарить цветы", 10}, {"Поставить лайк", 5}, {"Сходить в кино", 25}
	};*/
	int prev_player_action = 0;
	int player_times = 0;

	int prev_rival_action = 0;
	int rival_times = 0;
	int action;
	short player_relation = 0, rival_relation = 0;
	list<int> bad_actions;
	
	//std::cout << "Hello, world!" << endl;
	//cout << "Welcome to the game Triumvirate of Hearts v.0.1" << endl;
	cout << "Добро пожаловать в игру Triumvirate of Hearts v.0.1" << endl;
	cout << endl;
	cout << "Выберете режим:" << endl;;
	cout << "0. Любовный треугольник" <<endl;
	cout << "1. Политик" << endl;
	cin >> mode;

	if (mode == 1) {
		actions = politic_actions;
		actions_relation = politic_actions_relation;
	}
	else if (mode == 0) {
		actions = love_actions;
		actions_relation = love_actions_relation;
	}
	string playername, enemyname, lovername;

	Player player;

	cout << "Укажите своё имя: ";
	cin >> playername;;
	player.set_name(playername);
	playername.clear();
	char answer;
	Lover lover;
	lover.generate_character();
	if (mode == 0) {
		cout << "Cгенерирована возлюбленная " << lover.generate_name() << endl;
		
		cout << "Оставить ли сгенированым имя? (y/n): ";
		cin >> answer;
		if (tolower(answer) == 'n') {
			cout << "Укажите имя для возлюбленной" << endl;;
			cin >> lovername;
			lover.set_name(lovername);
			lovername.clear();
		}
	}
	else if (mode == 1) {
		cout << "Сгенерирован народ" << endl;
		lover.set_name("Народ");
	}
	
	Enemy enemy;
	cout << "Cгенерирован противник " << enemy.generate_name() << endl;
	//enemy.get_name();
	cout << "Оставить ли сгенированым имя? (y/n): ";
	cin >> answer;
	if (tolower(answer) == 'n') {
		cout << "Укажите имя для противника" << endl;;
		cin >> enemyname;
		enemy.set_name(enemyname);
		enemyname.clear();
	}
	/*for (short i : preferences)
	{
		cout << i << "\t";
	}*/
	cout << endl;
	//std::cout << "1. Подарить цветы\n2. Поставить лайк\n3. Сходить в кино" <<endl;
	while (true) {
		if (player.get_relation() < 0 || enemy.get_relation() >= 300) {
			//cout << "You lose";
			cout << "Вы проиграли, " << lover.get_name() << " выбрала " << enemy.get_name()<<endl;
			break;
		}
		else if (player.get_relation() >= 300 || enemy.get_relation() < 0) {
			//cout << "The player won";
			cout << "Вы выиграли, " << lover.get_name() << " выбрала Вас" << endl;
			break;
		}
		for (size_t i = 0; i < 6; i++)
		{
			cout << i << ". " << actions[i] <<" ("<<actions_relation[i]<<" очков)" << endl;
		}
		//cout << "Which of these actions will you choose? ";
		cout << "Какое из этих действий выберешь ты? ";
		cin >> action;	
		if (mode == 0) {
			if (action == prev_player_action)
				player_times++;
			else
				player_times = 0;
			prev_player_action = action;
			//cout << "The player chose \"" << actions[action] << "\"" << endl;
			cout << player.get_name() << " " << "выбрал \"" << actions[action] << "\"" << endl;
			if (player_times >= 2) {
				//cout << "I am tired of this! Can't think of anything better?" << endl;
				cout << "Мне это надоело! Ничего лучшего не придумал?" << endl;
				//player_relation -= 20;
				player.increase_relation(-20);
			}
			else

				//player_relation += lover.appreciation(action, actions_relation);
				player.increase_relation(lover.appreciation(action, actions_relation));
			//player_relation += actions_relation[action] + preferences[action];
		}
		else if (mode == 1) {
			cout << player.get_name() << " " << "выбрал \"" << actions[action] << "\"" << endl;
			player.increase_relation(lover.appreciation(action, actions_relation));
		}
			

		cout << player.get_name() << ": " << player.get_relation() 
		<< " | " << enemy.get_name()<<": " << enemy.get_relation() << endl;
		cout << endl;
		while (true) {
			action = rand() % 6;
			if (!findValue(bad_actions, action))
				break;

		}
		
		//cout << "The enemy chose \"" << actions[action] << "\"" << endl;
		cout << enemy.get_name()<< " " << "выбрал \"" << actions[action] << "\"" << endl;
		//if (action == prev_rival_action)
		//	rival_times++;
		//else
		//	rival_times = 0;
		//prev_rival_action = action;
		short result;
		//if (rival_times >= 2) {
		//	cout << "Мне это надоело! Ничего лучшего не придумал?" << endl;
		//	rival_relation -= 20;
		//}
		//else {
			result = lover.appreciation(action, actions_relation);
			enemy.increase_relation(result);
		//}

		//rival_relation += actions_relation[action] + preferences[action];
	
		//cout << "Player: " << player_relation << " " << "Enemy: " << rival_relation << endl;
		cout << player.get_name() << ": " << player.get_relation() << " | " << enemy.get_name() << ": " << enemy.get_relation() << endl;

		if (result < actions_relation[action])
			bad_actions.push_back(action);
		/*for (int n : bad_actions)
			cout << n << "\t";
		cout << endl;*/

	}
	return 0;
}