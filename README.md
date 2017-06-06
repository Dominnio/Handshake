# Handshake

Program sprawdzający czy jeśli każda osoba w N osobowej grupie wymieni K uścisków (każdy uścisk z inną osobą) to czy wszystkie osoby w tej grupie są połączone 'grafem uściśnięć'.
Po wywołaniu wypisywane są informacje o tym kto komu podał rękę. Czasami zdarza się, że konieczna jest modyfikacja wymagń. Np. jeśli w trzyosobowej grupie każdy ma wymienić 1 uścisk to jedna osoba pozostanie bez uścisku.
Następnie wyświetlany jest graf połaczeń (tworzony za pomocą algorytmu Dijkstry). Liczba oznaczaw jakiej odległości od danej osoby znajduje się inna osoba. Np. jeśli dwie osoby są bezpośrednio polączone to wypisana będzie liczba 1, jesli dzielą je dwie inne osoby to wypisane będzie liczba 3. W przypadku braku połączenia wypisane zostanie 'i'.
