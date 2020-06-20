#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <future>

using namespace std;

/*
 * thread
 *	function
 *	function class member
 * mutex
 * future
 */

static bool Stopped = false;
mutex guard;
void Send(string message)
{
	guard.lock();
	cout << message << "\n";
	guard.unlock();
}

void DoWork(string name)
{
	cout << name + " thread started -> Id: " << this_thread::get_id() << "\n";

	while (!Stopped)
	{
		Send(name + "-> " + name + " job...");
		//cout << name << "-> " << name << " job..." << endl;
		this_thread::sleep_for(100ms);
	}
}

void SendMessage(string poruka)
{
	cout << "Poruka: " << poruka << "\n";
	for (int i = 0; i < 10; ++i)
		cout << "Slanje poruke...\n";
}

class Notification
{
	vector<string> _notifications;
public:
	void SendNotification()
	{

	}
	int GetNotificationsNumber()
	{
		return _notifications.size();
	}
	void AddNotification(string message)
	{
		_notifications.push_back(message);
	}
	void SendMessage(string message)
	{
		DoWork(message);
	}
	vector<string> GetNotifications()const {
		return _notifications;
	}
};
int Get()
{
	return 222;
}
int main()
{
	Notification notif;
	notif.AddNotification("Nofitication 1");
	notif.AddNotification("Nofitication 2");
	notif.AddNotification("Nofitication 3");

#pragma region Intro
#if 1

	cout << "Broj niti: " << thread::hardware_concurrency() << endl;


	thread t1(SendMessage, "How are you");


	
	t1.detach(); // main thread no longer waits for t1 execution

#endif
#pragma endregion

	for (string n : notif.GetNotifications())
		cout << n<<endl;

	for (int i = 0; i < 20; ++i)
		cout << i << "\n";
	
#pragma region Thread
#if 0
	cout << "Main thread Id: " << this_thread::get_id() << "\n";
	thread worker(DoWork, "Worker");
	thread notifThread(&Notification::SendMessage, notif, "Notification message");

	while (!Stopped)
		DoWork("Main");

	cin.get();
	// await in c# | lock the current thread and wait for this to finish
	worker.join();
	notifThread.join();
	Stopped = true;

#endif
#pragma endregion

#pragma region Future
#if 0
	future<int> notifNumber = async(&Notification::GetNotificationsNumber, notif);
	future<int> getNumber = async(Get);
	cout << notifNumber.get() << endl;
	cout << getNumber.get() << endl;
#endif
#pragma endregion

}