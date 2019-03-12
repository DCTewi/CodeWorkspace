#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<int, string> personel;
	typedef map<int, string> UDT_MAP_INT_STRING;
	UDT_MAP_INT_STRING enumMap;

	map<int, string> mapStudent;
	mapStudent.insert(pair<int, string>(5, "one"));
	for (auto student : mapStudent)
	{
		printf("%d %s\n", student.first, student.second);
	}
	for (auto student = mapStudent.begin(); student!=mapStudent.end(); student++)
	{
		printf("%d %s\n", student->first, student->second);
	}

	mapStudent.insert(map<int, string>::value_type (1, "Two"));

	for (auto student = mapStudent.begin(); student!=mapStudent.end(); student++)
	{
		printf("%d %s\n", student->first, student->second);
	}

	mapStudent[3] = "666,aad";
	for (auto student = mapStudent.begin(); student!=mapStudent.end(); student++)
	{
		printf("%d %s\n", student->first, student->second);
	}

	printf("%d\n", mapStudent.size());

	if (mapStudent.find(1) != mapStudent.end())
	{
		cout<<mapStudent[1]<<endl;
	}

	mapStudent.erase(1);
	for (auto stu : mapStudent)
	{
		cout<<stu.first<<" "<<stu.second<<endl;
	}

	mapStudent.empty();

	return 0;
}