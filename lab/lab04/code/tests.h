#ifndef INCLUDE_TESTS
#define INCLUDE_TESTS

#include "string.h"

struct test_strings{
	static const string hw;
	static const string li;
};

const string
test_strings::hw = "Hello World";

const string
test_strings::li = R"FOO(Adipisci quo iste vel nostrum. Ipsum inventore sit sed eum vel. Laborum consectetur earum eligendi.
Ad qui in exercitationem aut veniam natus voluptatem. Natus ducimus labore odio ipsum. Eos numquam rerum debitis non sint nobis cum et.
Omnis et est corporis reprehenderit quaerat quia reiciendis. Tempora quis illum temporibus a tempore accusantium omnis mollitia. Aut consectetur facere dolorem molestiae error.
Quaerat eos ad nemo odit ratione vero quo iure. Sapiente asperiores molestiae ut natus officia unde aut facere. Aut vitae aut autem unde culpa. Corrupti pariatur expedita qui mollitia nemo similique repudiandae eos.
Officiis delectus ipsum rem. Ad in et rerum. Error assumenda iusto ea amet minima consequatur in vel.)FOO";


#endif
