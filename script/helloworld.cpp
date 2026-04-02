#include <gazebo/gazebo.hh>
#include <iostream>

namespace gazebo
{
  class RuanWorldPlugin : public WorldPlugin
  {
    public: RuanWorldPlugin() : WorldPlugin()
    {
    }

    public: void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
    {
      std::cout << "Hello World, This is Ruan first project" << std::endl;
    }
  };

  GZ_REGISTER_WORLD_PLUGIN(RuanWorldPlugin)
}
