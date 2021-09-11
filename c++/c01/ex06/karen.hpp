#ifndef KAREN
# define KAREN
# include <string>

class karen
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	void (karen::*fnptr[4])();
	std::string inputOptions[4];

public:
	karen(/* args */);
	~karen();
	void complain(std::string level);
	void filter(std::string input);
};
#endif
