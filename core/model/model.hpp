#ifndef MODELHPP
#define MODELHPP

namespace CAT {

    template <typename Schema> class Model {

        private:
            Schema schema;

        public:

            Model(Schema schema){
                this->schema = schema;
            }


            void load(Schema schema){
                this->schema = Schema;
            }

            Schema get(){
                return this->schema;
            }

    };


};

#endif