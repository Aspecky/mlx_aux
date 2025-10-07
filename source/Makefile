NAME := mlx_aux.a

LIBS := mlx_aux algorithms

CLASSES :=	Color4 \
			HookService

UNITS := $(LIBS) $(CLASSES)

ARCHIVES := $(foreach unit,$(UNITS),$(unit)/$(unit).a)

OBJS := $(foreach unit,$(UNITS),$(patsubst ./%.o,$(unit)/%.o,$(shell make -s print-OBJS -C $(unit))))

INC_DIR := ./include
HEADERS = $(foreach unit,$(UNITS),$(INC_DIR)/$(unit).h)

CC := cc

all: $(NAME)

$(NAME): $(HEADERS) $(ARCHIVES) | $(INC_DIR)
	ar -rcs $(NAME) $(OBJS)

.SECONDEXPANSION:
%.a: $$(wildcard $$(dir $$@)*.[ch])
	make all -C $(dir $@)

$(INC_DIR):
	make -p $(INC_DIR)

.SECONDEXPANSION:
$(INC_DIR)/%.h: %/$$(notdir $$@)
	cp $< $@

.PHONY: headers
headers:
	$(foreach unit,$(UNITS),cp $(unit)/$(unit).h $(INC_DIR);)

.PHONY: clean
clean:
	$(foreach unit,$(UNITS),make clean -C $(unit);)

fclean: clean
	rm -f $(NAME)
	$(foreach unit,$(UNITS),make fclean -C $(unit);)

re: fclean all

print-%:
	@echo $($*)
