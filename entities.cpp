struct vector3 {
	double x;
	double y;
	double z;
}

class Entitiy {
	public:
		vector3 pos;

		char flags;
		bool onFire;
		bool crouched;
		bool riding;
		bool sprinting;
		bool rightClickAction;

		short drowning_counter;
		int potion_effects;

	int setPos(double x, double y, double z) {
		pos.x = x;
		pos.y = y;
		pos.z = z;
	}

	int setPos(vector3 p) {
		pos = p;
	}
};
