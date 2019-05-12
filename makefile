#Allegro libraries that have to link
ALLEGRO_OPTIONS := -lallegro -lallegro_image -lallegro_font -lallegro_ttf -lallegro_audio -lallegro_acodec

#CPP compiler
CPP := g++

#All source files
SRCS := $(shell find src -type f -name "*.cpp")

#All object files
OBJS := $(patsubst src/%,./obj/%.o,$(basename $(SRCS)))

#Creates a directory where put object files
$(shell mkdir -p obj >/dev/null)

digdug : $(OBJS)
	$(CPP) $(OBJS) -o digdug $(ALLEGRO_OPTIONS)

./obj/%.o : ./src/%.cpp 
	$(CPP) -c $^ -o $@
	
.PHONY: clean
clean:
	rm -r obj
