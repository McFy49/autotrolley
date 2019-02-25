CXX=g++

autodriver:
	$(CXX) -o sources/autodriver/autodriver sources/autodriver/autodriver.cpp

clean:
	rm -rf sources/autodriver/autodriver
