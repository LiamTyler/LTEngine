MAINDIR = $(realpath ./)
BUILDDIR = $(MAINDIR)/build
SRCDIR = $(MAINDIR)/src
BINDIR = $(BUILDDIR)/bin
OBJDIR = $(BUILDDIR)/obj
EXTDIR = $(MAINDIR)/ext
CXX = g++
CXXLIBS += -lGLEW -lSDL2 -lGL -lGLU -ldl
CXXFLAGS += -I$(MAINDIR) -I$(EXTDIR) -std=c++11

rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))
make-depend-cxx=$(CXX) $(CXXFLAGS) -MM -MF $3 -MP -MT $2 $1

SOURCES = $(SRCDIR)
SRC_CXX = $(call rwildcard,$(SOURCES),*.cpp)
OBJECTS_CXX = $(notdir $(patsubst %.cpp,%.o,$(SRC_CXX)))
LIBNAME = libProgression.a
LIBPATH = $(BUILDDIR)/$(LIBNAME)
LIBLINK = -L$(BUILDDIR) -lProgression

EXAMPLEDIR = $(MAINDIR)/examples
EXAMPLE_SRC = $(notdir $(call rwildcard,$(EXAMPLEDIR),*.cpp))
EXAMPLE_EXES = $(basename $(EXAMPLE_SRC))

.PHONY: all clean lib examples info

all: $(LIBPATH) examples

clean:
	rm -rf $(BUILDDIR)
	rm -f $(EXAMPLEDIR)/*.o

lib: $(LIBPATH)

examples: $(addprefix $(EXAMPLEDIR)/, $(EXAMPLE_EXES))

$(LIBPATH): $(addprefix $(OBJDIR)/, $(OBJECTS_CXX)) | $(BINDIR)
	rm -f $(LIBPATH)
	ar -csq $(LIBPATH) $(OBJDIR)/*.o

ifneq "$MAKECMDGOALS" "clean"
-include $(addprefix $(OBJDIR)/,$(OBJECTS_CXX:.o=.d))
endif

$(addprefix $(OBJDIR)/, $(OBJECTS_CXX)): | $(OBJDIR)

$(BINDIR) $(OBJDIR):
	mkdir -p $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(call make-depend-cxx,$<,$@,$(subst .o,.d,$@))
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -c -o $@ $<

$(EXAMPLEDIR)/%: $(EXAMPLEDIR)/%.cpp $(LIBPATH)
	$(CXX) $< $(LIBLINK) $(CXXFLAGS) $(CXXLIBS) -o $@
