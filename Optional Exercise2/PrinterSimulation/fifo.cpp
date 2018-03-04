//: fifo.h linpeiwen
#include "fifo.h"
#include "event.h"
#include <queue>

using namespace std;

/*
 * The method reading and processing a list of events from a data file,simulate the printer using.
 */
void fifo::simulate(string file) {

	//First load the data file using the inherited loadworkload
	loadworkload(file);
	int num_job = 0;
	int service = 0;
	double total_latency = 0;
	double mean_latency = 0;
	queue<event> arrived;	

	num_job = workload.size();
	cout << "FIFO Simulation" <<"\n" << endl;
	service = workload.front().arrival_time();

	//counter variable to counter time by add one. 
	for(int counter = 0;;counter++) {

		//output the arriving print job if the job's arrival_time equals the counter.
		while(!workload.empty()) {

			if(workload.front().arrival_time() == counter) {
					arrived.push(workload.front());	
					cout<< "      Arriving: "<< workload.front().getjob().getnumpages() 
						<< " pages from " << workload.front().getjob().getuser() << " at " 
						<< workload.front().arrival_time() << " seconds" <<endl;			
					workload.pop();	
			} else {
				break;
			}	
		}

		//output the being servicing print job if the service time equals the counter.
		while(!arrived.empty()) {
			
			if(service == counter) {
				total_latency= total_latency + (service - arrived.front().arrival_time());
				cout<< "      Servicing: " << arrived.front().getjob().getnumpages() << " pages from "
					<< arrived.front().getjob().getuser() << " at " << service << " seconds" <<endl;			
				service = service + arrived.front().getjob().getnumpages() * seconds_per_page;		
				arrived.pop();	
			} else {
				break;
			}			
		}

		//if all the job arrived and all have been serviced then break.
		if(workload.empty() && arrived.empty()) {
			break;
		}
	}

	mean_latency = total_latency/7;
	cout<< "\n\n";

	//output the extra information
	cout<< "      Total jobs: " << num_job << "\n"
		<< "      Aggregate latency: " << total_latency << " seconds" << "\n"
		<< "      Mean latency: " << mean_latency << " seconds " << endl;
}
///:~