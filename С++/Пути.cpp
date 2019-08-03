/*#include<iostream>
#include<string>
#include<vector>
using namespace std;
int ComputeDistance(const string& source, const string& destination) {
	return (source.length() - destination.length());
}
class Route {
public:
	Route() {
		SetSource("Moskow");
		SetDestination("Vologda");
	}
	Route(const string& source, const string& destination) {
		SetSource(source), SetDestination(destination);
	}
	string GetSource() const { return source; }
	string GetDestination() const { return destination; }
	int GetLength() const { return length; }
	void SetSource(const string& new_source) { source = new_source; UpdateLength(); }
	void SetDestination(const string& new_destination) { destination = new_destination; UpdateLength(); }
private:
	void UpdateLength() { length = ComputeDistance(source, destination); }
	string source;
	string destination;
	int length;
};
void PrintRoute(const Route& route) {
	cout << route.GetSource() << " - " << route.GetDestination() << "\n";
}
void ReverseRoute(Route& route) {
	string old_source = route.GetSource();
	string old_destination = route.GetDestination();
	route.SetDestination(old_source);
	route.SetSource(old_destination);
}
int main() {
	Route route;
	PrintRoute({});
	ReverseRoute(route);
	PrintRoute(Route("Minsk", "Paris"));
	vector<Route> routes;
	routes.push_back({ "London", "BSUIR" });
	getchar();
	return 0;
}*/