#include <iostream>
using namespace std;

class PrintJobs {
        static int nTrayPages;
        static int nJobs;
        int n_pages;

        public:
            PrintJobs(int pages): n_pages(pages) {
                nTrayPages-=pages;
                nJobs++;
                cout << "Printing " << n_pages << " pages"<< endl;
                cout << "Pages left in tray: " << nTrayPages << endl;
                cout << "Total print jobs: " << nJobs << endl;
                }

                static void loadTrayPages(int pages) {
                    nTrayPages += pages;
                }

                static int getTrayPages() {
                    return nTrayPages;
                }

                static int getJobsCount() {
                    return nJobs;
                }


};

int PrintJobs::nTrayPages = 500;
int PrintJobs::nJobs = 0;

int main(){
    cout << "Jobs = " << PrintJobs:: getJobsCount()<< endl;
    cout << "Pages = " << PrintJobs:: getTrayPages() << endl;
    PrintJobs job1(30), job2(20);
}