EXEC = test
CPPFLAGS += -Iplugins -Wall

all: $(EXEC) plugins

libmanager.so: plugins/plugin_factory_manager.cpp
	$(CXX) $(CPPFLAGS) -shared -fPIC $^ -o libmanager.so

plugs/plugin1.so: plugins/plugin1.cpp
	$(CXX) $(CPPFLAGS) -shared -L. -lmanager -fPIC -g $^ -o $@

plugs/plugin2.so: plugins/plugin2.cpp
	$(CXX) $(CPPFLAGS) -shared -L. -lmanager -fPIC -g $^ -o $@

plugs/plugin3.so: plugins/plugin3.cpp
	$(CXX) $(CPPFLAGS) -shared -L. -lmanager -fPIC -g $^ -o $@

plugins: libmanager.so plugs/plugin1.so plugs/plugin2.so plugs/plugin3.so
	
$(EXEC): libmanager.so main.cpp
	$(CXX) $(CPPFLAGS) -ldl -L. -lmanager -dPIC -fPIC -g main.cpp -o $@

clean:
	rm -f *.o *.so plugs/*.so
	rm -f $(EXEC)
