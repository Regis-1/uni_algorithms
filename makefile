CXX=g++
LIBFLAGS=
CXXFLAGS=-Wall -pedantic

OBJDIR=obj
SRCDIR=src
INCDIR=include

TARGET=s0rt_my_life
CORES=main Manager Sorter 
SRCS=$(patsubst %,$(SRCDIR)/%.cpp,$(CORES))
OBJS=$(patsubst %,$(OBJDIR)/%.o,$(CORES))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LIBFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I/$(INCDIR) $(LIBFLAGS)

.PHONY: clean

clean:
	rm -rf $(OBJDIR)/*.o $(TARGET)
