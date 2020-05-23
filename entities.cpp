struct vector3 {
	double x;
	double y;
	double z;
}

class Entitiy {
	public:
		vector3 pos;

		int eid; // Entity ID

		char flags;
		short drowning_counter;
		int potion_effects; // DONT UNDERSTAND
		int animal_timer; // SHOULD BE MOB SPECIFIC?

		void setPos(double x, double y, double z) {
			pos.x = x;
			pos.y = y;
			pos.z = z;
		}

		void setPos(vector3 p) {
			pos = p;
		}
};

class Mob : public Entity {
	public:
		char type;

		char yaw;
		char pitch;

		char head_yaw;

}

class Object : public Entity {
	public:
		char type;
		int fireball_thrower_id;
		vector3 speed; // Specific to fireball throwser's id
}

class Creeper : public Mob {
	public:
		vector3 dimensions;

		char status; // -1 to 1
		char charged; // 1 - charged, 0 - not

		void init() {
			dimensions.x = 0.6;
			dimensions.y = 1.8;
			dimensions.z = 0.6;

			charged = (char)0;
		}
}

class Spider : public Mob {
	public:
		vector3 dimensions;

		char aggression; // Unknown Value

		void init() {
			dimensions.x = 1.4;
			dimensions.y = 0.9;
			dimensions.z = 1.4;
		}
}

class Sheep : public Mob {
	public:
		vector3 dimensions;
		char wool_status;

		void init() {
			dimensions.x = 0.6;
			dimensions.y = 1.3;
			dimensions.z = 0.6;
		}
}
