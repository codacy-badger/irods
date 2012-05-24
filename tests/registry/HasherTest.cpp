#include "Hasher.h"
#include "MD5Strategy.h"
#include "SHA256Strategy.h"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void
generateHash(
    const char* filename)
{
    // Create hasher
    Hasher hasher;
    MD5Strategy* md5Strategy = new MD5Strategy();
    hasher.addStrategy(md5Strategy);
    SHA256Strategy* sha256Strategy = new SHA256Strategy();
    hasher.addStrategy(sha256Strategy);
    
    // Read the file and hash it
    ifstream input(filename);
    if(input.is_open()) {
	char buffer[1024];
	hasher.init();
	while(input.good()) {
	    input.get(buffer, 1024);
	    if(input.good()) {
		string data(buffer);
		hasher.update(data);
	    }
	}
	input.close();
	string messageDigest;
	hasher.digest("MD5", messageDigest);
	cout << "MD5 Hash Digest: " << messageDigest << endl;
	hasher.digest("SHA256", messageDigest);
	cout << "SHA256 Hash Digest: " << messageDigest << endl;
    } else {
	cerr << "ERROR: Unable to open file: " << filename << endl;
    }
}

int
main(
    int argc,
    char* argv[])
{
    int result = 0;
    if(argc != 2) {
	cerr << "ERROR: wrong number of arguments: " << argc << endl;
	cerr << "ERROR: filename must be specified" << endl;
	result = 1;
    } else {
	generateHash(argv[1]);
    }
    return result;
}
