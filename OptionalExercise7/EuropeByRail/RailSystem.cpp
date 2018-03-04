//RailSystem.h linpeiwen
#pragma warning (disable:4786)
#pragma warning (disable:4503)

#include "RailSystem.h"

//Reset the data objects of the City objects' contained in cities.
void RailSystem::reset(void) {

    // TODO: reset the data objects of the 
    // City objects' contained in cities
	map<string,City*>::iterator cities_it;

	//Iterate through the cities to reset the city objects.
	for(cities_it = cities.begin();cities_it != cities.end();cities_it++) {

		cities_it->second->name = cities_it->first; 
		cities_it->second->visited = false;
		cities_it->second->total_fee = 0;
		cities_it->second->total_distance = 0;
		cities_it->second->from_city = "";
	}    
}

RailSystem::RailSystem(string const &filename) {
    
    load_services(filename);
}

//Load the services from the file
void RailSystem::load_services(string const &filename) {

	ifstream inf(filename.c_str());
	string from, to;
	int fee, distance;

	while ( inf.good() ) {

		// Read in the from city, to city, the fee, and distance.
		inf >> from >> to >> fee >> distance;

		if ( inf.good() ) {
		
			// TODO: Add entries in the cities container and
			// and services in the rail system for the new 
            // cities we read in.						
			Service* sv = new Service(to,fee,distance);	
			
			//If the city has not created,create the city and map the city to cities.
			if(!is_valid_city(from)) {

				City* city = new City(from);
				cities[from] = city;				
			}

			outgoing_services[from].push_back(sv);			
		}
	}
	
	inf.close();
}

RailSystem::~RailSystem(void) {

    // TODO: release all the City* and Service*
    // from cities and outgoing_services
	map<string,City*>::iterator cities_it;
	map<string, list<Service*> >::iterator serv_it;
	list<Service*> serv_list_it;

	//delete the city objects.
	for(cities_it = cities.begin();cities_it != cities.end();cities_it++) {
		
		delete cities_it->second;
	}

	//delete the service objects.
	for(serv_it = outgoing_services.begin();serv_it != outgoing_services.end();serv_it++) {

		serv_list_it = serv_it->second;

		while(!serv_list_it.empty()) {
			
			//Grap the service,and pop the ser_list_it then delete the service.It is necessery.
			Service* sv = serv_list_it.front(); 			
			serv_list_it.pop_front();

			delete sv;
		}		
	}
}

void RailSystem::output_cheapest_route(const string& from,
                const string& to, ostream& out) {

	reset();
	pair<int, int> totals = calc_route(from, to);

	if (totals.first == INT_MAX) {
		out << "There is no route from " << from << " to " << to << "\n";
	} else {
		out << "The cheapest route from " << from << " to " << to << "\n";
		out << "costs " << totals.first << " euros and spans " << totals.second
			<< " kilometers\n";
        cout << recover_route(to) << "\n\n";
	}
}

bool RailSystem::is_valid_city(const string& name) {

	return cities.count(name) == 1;
}

//Implement Dijkstra's shortest path algorithm to find the cheapest route between the cities 
pair<int, int> RailSystem::calc_route(string from, string to) {

	priority_queue<City*, vector<City*>, Cheapest> candidates;

    // TODO: Implement Dijkstra's shortest path algorithm to
    // find the cheapest route between the cities
	City* city;
	
	//first push the from city.
	candidates.push(cities[from]);
	
	int citynode = 0;

	for(;citynode < cities.size();citynode++) {
	
		//If the candidates is empty,Stop loop.
		if(candidates.empty()) {
	
			break;
		}
		
		//Find an unvisited vertex
		city = candidates.top();
		city->visited = true;
		candidates.pop();	
		
				
		for(list<Service*>::iterator it = outgoing_services[city->name].begin();it != outgoing_services[city->name].end();it++) {
			
			// Find the edge.
			Service* sv	= *it;
			City* w = cities[sv->destination];
			int cvm = sv->fee;			
			
			// Update the city's total_fee and then push the city to the candidates.
			if(!w->visited || w->total_fee > city->total_fee + cvm){
			
				w->total_fee = city->total_fee + cvm;
				w->total_distance = city->total_distance + sv->distance;
				w->visited = true;
				w->from_city = city->name;
				candidates.push(w);				
			}
		}
	}

	// Return the total fee and total distance.
	// Return (INT_MAX, INT_MAX) if not path is found.
	if (cities[to]->visited) {
		return pair<int,int>(cities[to]->total_fee, cities[to]->total_distance);
	} else {
		return pair<int,int>(INT_MAX, INT_MAX);
 	}

}

string RailSystem::recover_route(const string& city) {
	
	// TODO: walk backwards through the cities
	// container to recover the route we found
	string path = "";
	vector<string> router;

	//first push the destination city.
	router.push_back(city);
	string from_city = cities[city]->from_city;

	//push back the previouse city of each citynode.
	while( from_city != "" ) {
	
		router.push_back(from_city);
		from_city = cities[from_city]->from_city;
	}

	path = router.back();
	router.pop_back();

	//output the router
	while( !router.empty()) {
	
		path +=  " to " + router.back();
		router.pop_back();
	}

	return path;
}
///:~