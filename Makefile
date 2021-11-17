SOURCE = main.cpp Application.cpp Chat.cpp NewMessages.cpp SHA1.cpp
TARGET = chat.out
UTILS_LIB = Utils
SHA_LIB = SHA
PREFIX = /usr/local/bin

out: $(SOURCE) lib_utils 
	g++ -o $(TARGET) $(SOURCE) -L. -l$(UTILS_LIB)

lib_utils: $(UTILS_LIB).cpp $(UTILS_LIB).h
	g++ -o $(UTILS_LIB).o $(UTILS_LIB).cpp -c
	ar rc lib$(UTILS_LIB).a $(UTILS_LIB).o

clean: 
	rm -rf *.o *.a
install:
	install $(TARGET) $(PREFIX)
uninstall:
	rm -rf $(PREFIX)/$(TARGET)

