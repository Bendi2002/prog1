#include "../std_lib_facilities.h"

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2){
	while(f1 != e1){
		*f2 = *f1;
		++f1;
		++f2;
	}
	return f2;
}

int main(){
	int array[10] = {0,1,2,3,4,5,6,7,8,9};
	int brrby[10];
	int crrcy[10];
	list<int> listb;
	list<int> listc;
	
	vector<int> vec1;
	vector<int> vec2;
	vector<int> vec3;

	for(int i = 0; i < 10; i++){
		vec1.push_back(i);
	}

	list<int> lista = {0,1,2,3,4,5,6,7,8,9};

	copy(begin(array), end(array), begin(brrby));

	cout << "array values:\n";
	for(int i = 0; i < 10; i++){
		cout << array[i] << " ";
	}
	cout << '\n';

	cout << "vec1 values:\n";
	for(int i = 0; i < 10; i++){
		cout << vec1[i] << " ";
	}
	cout << '\n';

	cout << "lista values:\n";
	for(auto const &i: lista){
		cout << i << " ";
	}
	cout << '\n';



	for(int i = 0; i < 10; i++){
		brrby[i] = array[i];
		vec2.push_back(vec1[i]);
	}


	cout << "brrby values:\n";
	for(int i = 0; i < 10; i++){
		cout << brrby[i] << " ";
	}
	cout << '\n';

	cout << "vec2 values:\n";
	for(int i = 0; i < 10; i++){
		cout << vec2[i] << " ";
	}
	cout << '\n';

	cout << "lista values:\n";
	for(auto const &i: lista){
		cout << i << " ";
	}
	cout << '\n';


	for(int i = 0; i < 10; i++){
		brrby[i] += 2;
		vec2[i] += 3;
	}

	for(auto i: lista){
		i = i + 5;
	}


	cout << "changed brrby values:\n";
	for(int i = 0; i < 10; i++){
		cout << brrby[i] << " ";
	}
	cout << '\n';

	cout << "changed vec2 values:\n";
	for(int i = 0; i < 10; i++){
		cout << vec2[i] << " ";
	}
	cout << '\n';

	cout << "changed lista values:\n";
	for(auto const &i: lista){
		cout << i << " ";
	}
	cout << '\n';

	my_copy(begin(lista), end(lista), begin(crrcy));

	cout << "mycopied crrcy values:\n";
	for(int i = 0; i < 10; i++){
		cout << crrcy[i] << " ";
	}
	cout << '\n';	

	int s1 = 3;
	int s2 = 27;

	auto search = find(begin(vec1), end(vec1), s1);
	auto search2 = find(begin(lista), end(lista), s2);

	if(search != end(vec1)){
		cout << s1 << " is found at location " << distance(begin(vec1), search) << '\n';
	}
	else{
		cout << s1 << " not found!\n";
	}

	if(search2 != end(lista)){
		cout << s2 << " is found at location " << distance(begin(lista), search2) << '\n';
	}
	else{
		cout << s2 << " not found!\n";
	}


	return 0;
}